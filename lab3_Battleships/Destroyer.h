#pragma once
#include "Ship.h"
class Destroyer :
	public Ship
{
public:
	Destroyer();
	~Destroyer();
	Ship* getPtr(int num);
	void setCoord(int y1, char x1, int y2, char x2, vector<vector<Ship*>> ptrmat, int num);

private:
	Ship* d1[2];
	Ship* d2[2];
	Ship* d3[2];
};

