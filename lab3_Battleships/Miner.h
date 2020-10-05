#pragma once
#include "Ship.h"
class Miner :
	public Ship
{
public:
	Miner();
	~Miner();
	Ship* getPtr(int num);
	void setCoord(int y1, char x1, vector <vector<Ship*>> ptrmat, int num);

	Ship* m1;
	Ship* m2;
	Ship* m3;
	Ship* m4;
};

