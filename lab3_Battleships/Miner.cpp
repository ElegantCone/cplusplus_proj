#include "Miner.h"



Miner::Miner()
{
}

Miner::~Miner()
{
}


void Miner::setCoord(int y1, char x1, vector <vector<Ship*>> ptrmat, int num) {
	int k = 0;
	Ship newShip = Ship();
	newShip.x1 = x1 - 'a';
	newShip.y1 = y1;
	switch (num)
	{
	case 0:
		this->m1 = &newShip;
		break;
	case 1:
		this->m2 = &newShip;
		break;
	case 2:
		this->m3 = &newShip;
		break;
	case 3:
		this->m4 = &newShip;
		break;
	}
	x1 = x1 - 'a';
	newShip.setInTable(y1, x1, ptrmat, MINER, &newShip);
}

Ship* Miner::getPtr(int num) {
	switch (num) {
	case 0:
		return this->m1;
		break;
	case 1:
		return this->m2;
		break;
	case 2:
		return this->m3;
		break;
	case 3:
		return this->m4;
	}
}