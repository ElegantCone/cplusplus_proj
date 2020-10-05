#pragma once
#include <limits>
#include <time.h>
#include <random>
#include <cassert>
#include "Table.h"
#include "Ship.h"
#include "Linkor.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Miner.h"
#include <map>
#include <memory>
//#include "CatchExceptions.h"
class Player
{
public:
	friend class Game;
	friend class Ship;
	Player();
	
	void setCoord();
	void setRandomCoord();
	void setIntellectCoord();
	void turn();
	void setEnemyTable(Table enemy);
	vector <vector <Ship*> > setPtrMatPlayer(int y1, char x1, int y2, char x2, int type);

	Table matrix;
	Table enemyM;
	vector <vector < Ship* >> newPtrMat;
	bool isHitted[10][10];
	//map <int, int, Ship*> mapOfShips;
	Miner oneP[4];
	Destroyer twoP[3];
	Cruiser threeP[2];
	Linkor lin;
	const string types[4] = { "Linkor", "Cruiser", "Destoyer" , "Miner" };
	string name;
	int countShips;
	int countP;
	int countPP;
	int countPPP;
	int curShip;
	int wins;
	int type; // 0 - humen, 1 - bot, 2 - II
	int lastx, lasty, isLastHitted, isLastKilled;
	int lastlastx, lastlasty;
	bool IsPrint;

	int countEnemyShips;
	//catch exceptions
	bool badCoord(int y1, char x1, int y2, char x2, int k);
	bool isItFits(int y1, int x1, int y2, int x2);
	void setEmptyPlayer(string name, int type, int wins);
	void makeShip(int y1, char x1, int y2, char x2, int k);
};

