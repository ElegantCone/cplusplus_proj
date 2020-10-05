#pragma once
//#include "Table.h"
#include <string>
#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>
#define UNKNOWN 0;
#define SET 1;
#define HIT 2;
#define KILLED 3;

using namespace std;
enum Types {
	UNKNOWN_T = -1,
	LINKOR = 0,
	CRUISER = 1,
	DESTROYER = 2,
	MINER = 3
};
class Ship
{
public:
	Ship(int x, int y, int type);
	Ship();
	//Ship& operator=(int coord);
	//Ship& operator[](int size);
	~Ship();

	void kill();

	int whatType();
	void setInTable(int x, int y, vector<vector<Ship*>> ptrmat, int type, Ship *ship);

	Ship* operator[](int N);
	Ship* getptr();
	friend class Player;
	//Ship* shipsPtr[20];
	//int curShip;
	//Ship* lastPtr;
	//int cRaw;	//coordinate x
	//int cCol; //coordinate y
	int hp; //HP of ship
	int type;
	int stat; //condition of the ship (setted = 1, killed = -1 or hitted = 0)
	int x1, x2, y1, y2;
};

