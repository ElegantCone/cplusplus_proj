#include "Linkor.h"



Linkor::Linkor()
{
	
}

void Linkor::setCoord(int y1, char x1, int y2, char x2, vector <vector<Ship*>> ptrmat) {
	
	int k = 0;
	Ship newShip = Ship();
	newShip.x1 = x1 - 'a';
	newShip.x2 = x2 - 'a';
	newShip.y1 = y1;
	newShip.y2 = y2;
	for (int k = 0; k < 4; k++) {
		//this->lin[k] = &newShip;
	}
	if (y2 > y1)
		for (int i = y1; i <= y2; i++) {
			int x = x1 - 'a';
			//newShip.setInTable(i, x, ptrmat, LINKOR, &newShip);
			k++;
		}
	else
		for (int i = x1 - 'a'; i <= x2 - 'a'; i++) {
			//newShip.setInTable(y1, i, ptrmat, LINKOR, &newShip);
			k++;
			//std::cout << "lin[" << k << "] equals ";
		}

}

