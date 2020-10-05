#pragma once
#include "Player.h"
#include "Parser.h"
class Game
{
public:
	void startGame(Parser pars);
	void startHum();
	void startHumBot();
	void startHumII();
private:
	Table emptyTable;
	Player p1;
	Player p2;
	
	int rounds;
};

