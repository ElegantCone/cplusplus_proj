#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "Ship.h"
using namespace std;

class Table
{
public:
	Table();

	void printMatrix(); //print tables (enemy is empty)

	void changeTable(int y1, int x1);
	void changeTable(int y1, int x1, int y2, int x2, int type); // 1 - setted, 0 - not.
	char getValue(int raw, int col);
	Ship* getPtr(int raw, int col);

	vector <vector <Ship*>> setPtrMat(int y1, char x1, int y2, char x2, int type);
	vector<vector<Ship*>> getptr();
	void clearTable();
	friend class Player;
	friend class Game;
	//bool isFit(int x1, char y1, int x2, char y2);

//private:
	char matrix[10][10];
	int matrixInt[10][10];
	vector <vector < Ship* > > ptrmat;
	int curShip;
	string raw = "   | a | b | c | d | e | f | g | h | i | j |        ";
	string enemyRaw = "|   |   |   |   |   |   |   |   |   |   |";
	void SetEmptyPlaces(int y1, int x1, int y2, int x2);
};

