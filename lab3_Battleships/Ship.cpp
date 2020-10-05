#include "Ship.h"


Ship::Ship()
{
	this->x1 = -1;
	this->x2 = -1;
	this->y1 = -1;
	this->y2 = -1;
	this->hp = 0;
	this->type = UNKNOWN_T;
	this->stat = UNKNOWN;
	//this->curShip = -1;
	
}

Ship::~Ship()
{
}

void Ship::setInTable(int x, int y, vector<vector<Ship*>> ptrmat, int type, Ship *ship) {
	Ship a = *ship;
	ship->type = type;
	ship->hp = 4 - type;
	ship->stat = SET;
}


Ship* Ship::getptr() {
	return this;
}
