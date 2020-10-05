#pragma once
#include "Ship.h"
#include <stdio.h>
#include <vector>
class Linkor :
	public Ship
{
public:
	Linkor();
	friend class Player;
	//Linkor(int y1, char x1, int y2, char x2);
	//void setCoord(int y1, char x1, int y2, char x2, Ship*** ptrmat);
	void setCoord(int y1, char x1, int y2, char x2, vector<vector<Ship*>> ptrmat);
private:
	//Ship* lin[4];
	Ship lin;
};

