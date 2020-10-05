#include <iostream>
#include <cmath>
#include "TritSet.h"
#define uintS (sizeof(unsigned int) * 4) //half of uint
using namespace std;


TritSet::Proxy::operator Trit() const {
	return this->value;
}

TritSet::TritSet(size_t size) {
	this->set = (unsigned int*)calloc(size / uintS, sizeof(unsigned int));
	this->lastTritIndex = -1;
	this->lastNotUnknownTritIndex = -1;
	this->falseCount = 0;
	this->trueCount = 0;
	this->size = size;
}

unsigned int TritSet::capacity() {
	return this->size;
}

void TritSet::fixSizes(TritSet& a, TritSet& b) {

	if (a.size > b.size)
		b.resize(a.size);
	if (b.size < a.size)
		a.resize(b.size);
}


void TritSet::resize(size_t newSize) {

	this->set = (unsigned int*)realloc(set,
		(newSize / uintS) * sizeof(unsigned int));
	this->size = newSize;
}

void TritSet::changeCountVars(Trit newValue, unsigned int index) {
	this->lastTritIndex = index;

	if (newValue != Trit::Unknown)
		this->lastNotUnknownTritIndex = index;

	if (newValue == Trit::False)
		this->falseCount += 1;
	else if (newValue == Trit::True)
		this->trueCount += 1;
}

TritSet::Proxy TritSet::operator[](size_t index) {

	return { index, this };
}

TritSet TritSet::operator&(TritSet setA) {

	fixSizes(setA, *this);
	TritSet resSet(this->size);

	for (unsigned int i = 0; i < this->size; ++i) {

		Trit a = (*this)[i];
		Trit b = setA[i];

		resSet[i] = a & b;
		resSet.changeCountVars(a | b, i);
	}
	return resSet;
}

TritSet TritSet::operator|(TritSet setA) {

	fixSizes(setA, *this);
	TritSet resSet(this->size);

	for (unsigned int i = 0; i < this->size; ++i) {

		Trit a = (*this)[i];
		Trit b = setA[i];
		resSet[i] = a | b;
		resSet.changeCountVars(a | b, i);
	}
	return resSet;
}

TritSet TritSet::operator~() {

	TritSet resSet(this->size);
	for (unsigned int i = 0; i < this->size; ++i) {
		Trit a = (*this)[i];
		resSet[i] = ~a;
		resSet.changeCountVars(~a, i);
	}

	return resSet;
}

TritSet::Proxy::Proxy(size_t index, TritSet* tritSet) {
	this->proxyIndex = index;
	this->value = index > tritSet->capacity() ?
		Trit::Unknown : 
		Trit( (tritSet->set[index / uintS] >> ((uintS - (index % uintS + 1)) * 2)) & 3u);
	this->setPtr = tritSet;
}

TritSet::Proxy& TritSet::Proxy::operator=(Trit newValue) {

	if (this->proxyIndex > this->setPtr->capacity() && newValue != Trit::Unknown)
		this->setPtr->resize(this->proxyIndex);

	if (this->proxyIndex <= this->setPtr->capacity() || newValue != Trit::Unknown) {

		this->setPtr->set[proxyIndex / uintS] =
			(this->setPtr->set[proxyIndex / uintS] &
			(~(3u << (uintS - (proxyIndex % uintS + 1)) * 2)))
			| ((unsigned int)newValue << (uintS - (proxyIndex % uintS + 1)) * 2);
	}

	this->setPtr->changeCountVars(newValue, proxyIndex);

	return *this;
}



void TritSet::shrink() {
	this->set = (unsigned int*)realloc(this->set, (this->lastTritIndex / uintS) * sizeof(unsigned int));
	this->size = this->lastTritIndex;
}

size_t TritSet::cardinality(Trit value) {
	switch (value) {
	case Trit::False:
		return this->falseCount;
	case Trit::True:
		return this->trueCount;
	case Trit::Unknown:
		return this->lastNotUnknownTritIndex + 1 - (this->trueCount + this->falseCount);
	}
	return -1;
}

std::size_t TritSet::TritHash::operator()(Trit t) const { return std::hash<int>()((int)t); }

std::unordered_map < Trit, int, TritSet::TritHash> TritSet::cardinality() {

	std::unordered_map < Trit, int, TritHash> resultMap = {
			{Trit::False, this->falseCount},
			{Trit::True,  this->trueCount},
			{Trit::Unknown,this->cardinality(Trit::Unknown)} 
	};

	return resultMap;
}

void TritSet::trim(size_t lastIndex) {

	this->set[lastIndex / uintS] = (this->set[lastIndex / uintS])
		& (((unsigned int)pow(2, (lastIndex * 2)) - 1)
			<< (sizeof(unsigned int) * 8 - lastIndex * 2));

	for (unsigned int i = lastIndex / uintS + 1; i < this->size - 1 / uintS; ++i) {
		this->set[i] = 0;
	}
}

size_t TritSet::length() {
	return lastNotUnknownTritIndex + 1;
}
