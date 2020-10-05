#include <iostream>
#include "Table.h"
#include "Player.h"
#include "Ship.h"
#include "Game.h"
#include "Parser.h"
using namespace std;


int main(int argc, char* argv[])
{
	Parser parser;
	int ret = parser.doWork(argc, argv);
	if (ret) return 0;
	/*string p1name, p2name;
	cout << "Write your name, Player 1! ";
	cin >> p1name;
	cout << "Write your name, Player 2! ";
	cin >> p2name;*/
	//пихнуть в option parser
	Game game;
	game.startGame(parser);
	//game.startHum();

}