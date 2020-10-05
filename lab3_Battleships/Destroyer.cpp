#include "Destroyer.h"


Destroyer::Destroyer() {

}

Destroyer::~Destroyer() {

}

void Destroyer::setCoord(int y1, char x1, int y2, char x2, vector <vector<Ship*>>ptrmat, int num) {
	int k = 0;
	Ship newShip = Ship();
	newShip.x1 = x1 - 'a';
	newShip.x2 = x2 - 'a';
	newShip.y1 = y1;
	newShip.y2 = y2;
	switch (num)
	{
	case 0:
		for (int i = 0; i < 2; i++) {
			this->d1[i] = &newShip;
		}
		break;
	case 1:
		for (int i = 0; i < 2; i++) {
			this->d2[i] = &newShip;
		}
		break;
	case 2:
		for (int i = 0; i < 2; i++) {
			this->d3[i] = &newShip;
		}
	}

	if (y2 > y1)
		for (int i = y1; i <= y2; i++) {
			int x = x1 - 'a';
			newShip.setInTable(i, x, ptrmat, DESTROYER, &newShip);
			k++;
		}
	else
		for (int i = x1 - 'a'; i <= x2 - 'a'; i++) {
			newShip.setInTable(y1, i, ptrmat, DESTROYER, &newShip);
			k++;
		}

}

Ship* Destroyer::getPtr(int num) {
	switch (num) {
	case 0:
		return this->d1[0];
		break;
	case 1:
		return this->d2[0];
		break;
	case 2:
		return this->d3[0];
		break;
	}
}