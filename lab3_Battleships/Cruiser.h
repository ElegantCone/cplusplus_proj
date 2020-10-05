#pragma once
#include "Ship.h"
#include <vector>
class Cruiser :
	public Ship
{
public:
	//void setCoord(int y1, char x1, int y2, char x2, int ind);
	Cruiser();
	~Cruiser();
	Ship* getPtr(int num);
	void setCoord(int y1, char x1, int y2, char x2, vector<vector<Ship*>> ptrmat, int num);

	//void setCoord(int y1, char x1, int y2, char x2, Ship* ptrmat[][], int num);
	Ship* cr1[3];
	Ship* cr2[3];
};

