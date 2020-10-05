#include "Game.h"

void Game::startHum() {
}

void Game::startGame(Parser pars) {
	p1.name = pars.p1name;
	p2.name = pars.p2name;
	rounds = pars.rounds;
	p1.type = pars.typeP1;
	p2.type = pars.typeP2;
	for (int i = 0; i < rounds; i++) {
		

		emptyTable.printMatrix();
		switch (p1.type)
		{
		case 0:
			p1.setCoord();
			break;
		case 1:
			p1.setRandomCoord();
			break;
		case 2:
			p1.setIntellectCoord();
			break;
		}
		system("pause");
		emptyTable.printMatrix();
		
		switch (p2.type)
		{
		case 0:
			p2.setCoord();
			break;
		case 1:
			p2.setRandomCoord();
			break;
		case 2:
			p2.setIntellectCoord();
			break;
		}
		//if (p1.type == 0 && p2.type != 0) p2.IsPrint = false;
		//if (p1.type != 0 && p2.type == 0) p1.IsPrint = false;
		system("pause");
		p1.setEnemyTable(p2.matrix);
		p2.setEnemyTable(p1.matrix);


		while (p1.countEnemyShips != 0 || p2.countEnemyShips != 0) {
			p1.turn();
			if (p1.countEnemyShips == 0) {
				p1.wins++;
				break;
			}
			p1.enemyM.printMatrix();
			cout << "Turn goes to Player 2!" << endl;
			system("pause");
			p2.turn();
			if (p2.countEnemyShips == 0) {
				p2.wins++;
				break;
			}
			p2.enemyM.printMatrix();
			cout << "Turn goes to Player 1!" << endl;
			system("pause");

		}
		cin.clear();
		cout << "Yay! Current score:\n" << p1.name << ": " << p1.wins << "\n" << p2.name << ": " << p2.wins << endl;
		if (i < rounds - 1) cout << "Press any button for continue." << endl;
		system("pause");
		p1.setEmptyPlayer(pars.p1name, pars.typeP1, p1.wins);
		p2.setEmptyPlayer(pars.p2name, pars.typeP2, p2.wins);
	}

}


//TODO: 1) clearTable - после одной партии затираем таблички, заполняем заново
//		2) поле type - в зависимости от типа игрока меняется стиль игры
//		3) методы turnRand() и turnII() - тут всё понятно