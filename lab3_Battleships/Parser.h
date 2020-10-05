#pragma once
#include <string.h>
#include <iostream>

using namespace std;

class Parser
{
public:
	Parser();


	int doWork(int argc, char* argv[]);

	friend class Game;

	int rounds;
	int typeP1, typeP2;
	string p1name, p2name; //0 - human, 1 - bot, 2 - II
	string info;
};

