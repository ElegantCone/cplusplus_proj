#include "Player.h"


Player::Player()
{
	this->countShips = 0;
	this->countP = 0;
	this->countPP = 0;
	this->countPPP = 0;
	this->countEnemyShips = 10;
	this->wins = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) isHitted[i][j] = false;
	}
	lastx = -1, lasty = -1;
	isLastHitted = false;
	isLastKilled = false;
	IsPrint = true;
	
}

void Player::setRandomCoord() {
	int y1, y2, x1int, x2int;
	srand(time(0));
	char x1, x2;
	int frcase;
	int k = 0;
	while (1) {
		y1 = rand() % 10;
		x1int = rand() % 10;
		x1 = 'a' + x1int;
		frcase = rand() % 2;
		switch (frcase)
		{
		case 0:
			x2 = x1;
			if (y1 + 3 - k > 9) y1 = 5 + k;
			y2 = y1 + 3 - k;
			break;
		case 1:
			y2 = y1;
			if (x1 - 'a' + 3 - k > 9) x1 = 5 + 'a' + k;
			x2 = x1 + 3 - k;
		}
		

		bool a = badCoord(y1, x1, y2, x2, k);
		if (a == true) {
			this->countShips++;
			this->matrix.changeTable(y1, x1 - 'a', y2, x2 - 'a', k);
			this->makeShip(y1, x1, y2, x2, k);
			this->matrix.printMatrix();
			if (this->countShips == 1 || this->countShips == 3 || this->countShips == 6) k++;
		}
		else {
			continue;
		}
		if (this->countShips == 10) break;
	}
}

void Player::setCoord() {
	char x1 = 0, x2 = 0;
	int y1 = 0, y2 = 0;
	int k = 0;
	while (1) {
		cout << "Write coordinates for " << this->types[k] << ": ";
		if (k < 3) {
			cin >> y1;
			cin >> x1;
			cin >> y2;
			cin >> x2;
		}
		else {
			cin >> y1;
			cin >> x1;
			y2 = y1; 
			x2 = x1;
		}

		if (y1 > y2) {
			int k = y1;
			y1 = y2;
			y2 = k;
		}
		else if (x1 > x2) {
			char k = x1;
			x1 = x2;
			x2 = k;
		}

		bool a = badCoord(y1, x1, y2, x2, k);
		if (a == true) {
			this->countShips++;
			this->matrix.changeTable(y1, x1 - 'a', y2, x2 - 'a', k);
			this->makeShip(y1, x1, y2, x2, k);
			this->matrix.printMatrix();
			if (this->countShips == 1 || this->countShips == 3 || this->countShips == 6) k++;
		}
		else {
			cout << "Bad coordinates! Try again!\n";
			std::cin.clear(),
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
			assert(std::cin);
		}
		if (this->countShips == 10) break;
	}
}

void Player::setIntellectCoord() {
	int y1, y2, x1int, x2int;
	srand(time(0));
	int xVar;
	char x1, x2;
	int frcase;
	int k = 0;
	while (1) {
		
		if (k < 3) {
			frcase = rand() % 2;
			switch (frcase)
			{
			case 0:
				y1 = rand() % 10;
				xVar = rand() % 2;
				x1 = (xVar == 0) ? 'a' : 'j';
				x2 = x1;
				if (y1 + 3 - k > 9) y1 = 5 + k;
				y2 = y1 + 3 - k;
				break;
			case 1:
				x1 = 'a' + rand() % 10;
				xVar = rand() % 2;
				if (x1 - 'a' + 3 - k > 9) x1 = 5 + 'a' + k;
				x2 = x1 + 3 - k;
				y1 = (xVar == 0) ? 0 : 9;
				y2 = y1;
			}
		}

		else {
			y1 = rand() % 10;
			x1int = rand() % 10;
			x1 = 'a' + x1int;
			frcase = rand() % 2;
			switch (frcase)
			{
			case 0:
				x2 = x1;
				if (y1 + 3 - k > 9) y1 = 5 + k;
				y2 = y1 + 3 - k;
				break;
			case 1:
				y2 = y1;
				if (x1 - 'a' + 3 - k > 9) x1 = 5 + 'a' + k;
				x2 = x1 + 3 - k;
			}
		}

		bool a = badCoord(y1, x1, y2, x2, k);
		if (a == true) {
			this->countShips++;
			this->matrix.changeTable(y1, x1 - 'a', y2, x2 - 'a', k);
			this->makeShip(y1, x1, y2, x2, k);
			this->matrix.printMatrix();
			if (this->countShips == 1 || this->countShips == 3 || this->countShips == 6) k++;
		}
		else {
			//std::cin.clear(),
			//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
			continue;
		}
		if (this->countShips == 10) break;
	}
}

bool Player::badCoord(int y1, char x1, int y2, char x2, int k) {
	try {
		if (y1 < 0 || y1 > 9 || y2 < 0 || y2 > 9 ||
			x1 < 'a' || x1 > 'j' || x1 < 'a' || x2 > 'j') throw 1;
		if ((y2 - y1 != (3-k)) && ((int)x2 - (int)x1) != (3-k)) throw 1;
		if (y2 - y1 == 3 - k) {
			if (x2 - x1 != 0) throw - 1;
		}
		else if (x2 - x1 == 3 - k)
			if (y2 - y1 != 0) throw - 1;
		

		if (((y2 - y1) == (3-k)) && (((int)x2 - (int)x1) == (3-k) && k != 3)) throw 1;
		//is it fits in a table?
		int y11, x11, y12, x12;
		y11 = y1 > 0 ? y1 - 1 : 0;
		x11 = (x1 - 'a') > 0 ? x1 - 'a' - 1 : x1 - 'a';
		y12 = y2 < 9 ? y2 + 1 : y2;
		x12 = (x2 - 'a') < 9 ? x2 - 'a' + 1 : x2 - 'a';
		if (isItFits(y11, x11, y12, x12) == false) throw 1;
	}
	catch (int) {
		return false;
	}

	return true;
}

bool Player::isItFits(int y1, int x1, int y2, int x2) {
	for (int i = y1; i <= y2; i++) {
		for (int j = x1; j <= x2; j++) {
			if (this->matrix.getValue(i, j) == '1') return false;
		}
	}
	return true;
}

void Player::makeShip(int y1, char x1, int y2, char x2, int k) {
	switch (k)
	{
	case 0:
		this->matrix.setPtrMat(y1, x1, y2, x2, LINKOR);
		//this->newPtrMat = this->setPtrMatPlayer(y1, x1, y2, x2, LINKOR);
		curShip++;
		break;
	case 1:
		this->countPPP++;
		this->matrix.setPtrMat(y1, x1, y2, x2, CRUISER);
		curShip++;
		break;
	case 2:
		this->matrix.setPtrMat(y1, x1, y2, x2, DESTROYER);
		this->countPP++;
		curShip++;
		break;
	case 3:
		this->matrix.setPtrMat(y1, x1, y2, x2, MINER);
		this->countP++;
		curShip++;
		break;
	}

}

void Player::setEnemyTable(Table enemy) {
	enemyM = Table();
	this->enemyM = enemy;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			this->enemyM.matrix[i][j] = ' ';
		}
	}
}

void Player::turn() {
	//все проверки в классе Game
	//если попали:
	srand(time(0));
	int y, x;
	char x1;
	this->enemyM.printMatrix();
	cout << name <<" turn" << endl;
	while (1) {
		switch (this->type) {
		case 0:
			while (1) {
				cout << "Enter coordinates: ";
				std::cin >> y;
				std::cin >> x1;
				x = x1 - 'a';
				if (y < 0 || y > 9 || x1 < 'a' || x1 > 'j' || this->enemyM.matrix[y][x] != ' ') {
					std::cin.clear(),
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
					assert(std::cin);
					this->enemyM.printMatrix();
					cout << "Player1's turn" << endl;
					cout << "Bad coordinates! Try again (num, char)" << endl;
					continue;
				}
				else break;
			}
			x = x1 - 'a';

			if (this->enemyM.matrixInt[y][x] > 0) {
				this->enemyM.matrixInt[y][x]--;
				Ship* a = new Ship();
				a = this->enemyM.ptrmat[y][x];
				a->hp--;
				this->enemyM.matrix[y][x] = '@';
				if (this->enemyM.ptrmat[y][x]->hp == 0) {
					this->enemyM.ptrmat[y][x]->stat = KILLED;
					this->enemyM.SetEmptyPlaces(enemyM.ptrmat[y][x]->y1, enemyM.ptrmat[y][x]->x1 - 'a', enemyM.ptrmat[y][x]->y2, enemyM.ptrmat[y][x]->x2 - 'a');
					countEnemyShips--;
					for (int i = 0; i < 4 - this->enemyM.ptrmat[y][x]->type; i++) {
						if (this->enemyM.ptrmat[y][x]->x1 < this->enemyM.ptrmat[y][x]->x2) {
							x = enemyM.ptrmat[y][x]->x1 - 'a';
							this->enemyM.matrix[y][i + x] = 'X';
						}
						else {
							y = enemyM.ptrmat[y][x]->y1;
							this->enemyM.matrix[i + y][x] = 'X';
						}
					}
				}
				std::cin.clear(),
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
				assert(std::cin);
				this->enemyM.printMatrix();
				cout << name << endl;
				if (this->countEnemyShips == 0) {
					cout << name << " win!" << endl;
					return;
				}
				continue;
			}
			else {
				this->enemyM.matrix[y][x] = '#';
				break;
			}

			break;
		case 1:
			//cout << name << endl;
			while (1) {
				x = rand() % 10;
				x1 = x + 'a';
				y = rand() % 10;
				if (y < 0 || y > 9 || x1 < 'a' || x1 > 'j' || this->enemyM.matrix[y][x] != ' ') {
					continue;
				}
				else break;
			}

			if (this->enemyM.matrixInt[y][x] > 0) {
				this->enemyM.matrixInt[y][x]--;
				Ship* a = new Ship();
				a = this->enemyM.ptrmat[y][x];
				a->hp--;
				this->enemyM.matrix[y][x] = '@';
				if (this->enemyM.ptrmat[y][x]->hp == 0) {
					this->enemyM.ptrmat[y][x]->stat = KILLED;
					this->enemyM.SetEmptyPlaces(enemyM.ptrmat[y][x]->y1, enemyM.ptrmat[y][x]->x1 - 'a', enemyM.ptrmat[y][x]->y2, enemyM.ptrmat[y][x]->x2 - 'a');
					countEnemyShips--;
					for (int i = 0; i < 4 - this->enemyM.ptrmat[y][x]->type; i++) {
						if (this->enemyM.ptrmat[y][x]->x1 < this->enemyM.ptrmat[y][x]->x2) {
							x = enemyM.ptrmat[y][x]->x1 - 'a';
							this->enemyM.matrix[y][i + x] = 'X';
						}
						else {
							y = enemyM.ptrmat[y][x]->y1;
							this->enemyM.matrix[i + y][x] = 'X';
						}
					}
				}
				std::cin.clear();
				this->enemyM.printMatrix();
				cout << name << endl;
				system("pause");
				if (this->countEnemyShips == 0) {
					cout << name << " win!" << endl;
					return;
				}
				continue;
			}
			else {
				this->enemyM.matrix[y][x] = '#';
				return;
			}

			break;

		case 2:
			int flag;
			while (1) {

				x = rand() % 10;
				x1 = x + 'a';
				y = rand() % 10;
				if (isLastHitted && !isLastKilled) {
					if (lastx == lastlastx) {
						x = lastx;
						y = 2 * lasty - lastlasty;
						if (y == 10 && !(this->enemyM.matrix[lastlasty - 1][lastx] != ' ')) y = lastlasty - 1;
						else if (this->enemyM.matrix[y][x] == '#') {
							if (y < lasty) {
								for (int i = 1; i < 10; i++) {
									if (this->enemyM.matrix[y + i][x] != '@') {
										y = y + i;
										break;
									}
								}
							}
							else if (y > lasty) {
								for (int i = 1; i < 10; i++) {
									if (this->enemyM.matrix[y - i][x] != '@') {
										y = y - i;
										break;
									}
								}
							}
						}
						if (y > 9 || y < 0) {
							if (lasty - 1 >= 0 && !(this->enemyM.matrix[lasty - 1][lastx] != ' ')) y = lasty - 1;
							else y = lasty + 1;
						}
					}

					else if (lasty == lastlasty) {
						y = lasty;
						x = 2 * lastx - lastlastx;
						if (x == 10 && !(this->enemyM.matrix[lasty][lastlastx] != ' ')) x = lastlastx - 1;
						else if (this->enemyM.matrix[y][x] == '#') {
							if (x < lastx) {
								for (int i = 1; i < 10; i++) {
									if (this->enemyM.matrix[y][x + i] != '@') {
										x = x + i;
										break;
									}
								}
							}
							else if (x > lastx) {
								for (int i = 1; i < 10; i++) {
									if (this->enemyM.matrix[y][x - i] != '@') {
										x = x - i;
										break;
									}
								}
							}
						}
						if (y > 9 || y < 0) {
							if (lasty - 1 >= 0 && !(this->enemyM.matrix[lasty - 1][lastx] != ' ')) y = lasty - 1;
							else y = lasty + 1;
						}
						if (x > 9 || x < 0 || !(this->enemyM.matrix[lasty][lastx - 1] != ' ')) {
							if (lastx - 1 >= 0 && !(this->enemyM.matrix[lasty][lastx - 1] != ' ')) x = lastx - 1;
							else x = lastx + 1;
						}
					}
					else if (lastx - 1 >= 0 && this->enemyM.matrix[lasty][lastx - 1] == ' ') {
						x = lastx - 1;
						x1 = lastx - 1 + 'a';
						y = lasty;
					}
					else if (lastx + 1 <= 9 && this->enemyM.matrix[lasty][lastx + 1] == ' ') {
						x = lastx + 1;
						x1 = lastx + 1 + 'a';
						y = lasty;
					}
					else if (lasty - 1 >= 0 && this->enemyM.matrix[lasty - 1][lastx] == ' ') {
						x = lastx;
						x1 = x + 'a';
						y = lasty - 1;
					}
					else if (lasty + 1 <= 9 && this->enemyM.matrix[lasty + 1][lastx] == ' ') {
						x = lastx;
						x1 = x + 'a';
						y = lasty + 1;
					}
					break;
				}

				if (y < 0 || y > 9 || x1 < 'a' || x1 > 'j' || this->enemyM.matrix[y][x] != ' ') {
					continue;
				}
				if (this->enemyM.matrix[y][x] == '#' || this->enemyM.matrix[y][x] == 'X') continue;
				else break;
			}


			if (this->enemyM.matrixInt[y][x] > 0) {
				this->enemyM.matrixInt[y][x]--;
				Ship* a = new Ship();
				a = this->enemyM.ptrmat[y][x];
				a->hp--;
				this->enemyM.matrix[y][x] = '@';
				isLastHitted = true;
				lastlastx = lastx;
				lastlasty = lasty;
				lastx = x;
				lasty = y;

				if (this->enemyM.ptrmat[y][x]->hp == 0) {
					this->enemyM.ptrmat[y][x]->stat = KILLED;
					this->enemyM.SetEmptyPlaces(enemyM.ptrmat[y][x]->y1, enemyM.ptrmat[y][x]->x1 - 'a', enemyM.ptrmat[y][x]->y2, enemyM.ptrmat[y][x]->x2 - 'a');
					isLastKilled = true;
					isLastHitted = false;
					lastlastx = -1; lastlasty = -1; lasty = -1; lastx = -1;
					countEnemyShips--;
					for (int i = 0; i < 4 - this->enemyM.ptrmat[y][x]->type; i++) {
						if (this->enemyM.ptrmat[y][x]->x1 < this->enemyM.ptrmat[y][x]->x2) {
							x = enemyM.ptrmat[y][x]->x1 - 'a';
							this->enemyM.matrix[y][i + x] = 'X';
						}
						else {
							y = enemyM.ptrmat[y][x]->y1;
							this->enemyM.matrix[i + y][x] = 'X';
						}
					}
				}
				std::cin.clear();
				this->enemyM.printMatrix();
				cout << name << endl;
				system("pause");
				if (this->countEnemyShips == 0) {
					cout << name << " win!" << endl;
					return;
				}
				continue;
			}
			else {
				isLastKilled = false;
				this->enemyM.matrix[y][x] = '#';
				return;
			}

			break;

		}
	}
}


void Player::setEmptyPlayer(string name, int type, int wins) {
	this->countShips = 0;
	this->countP = 0;
	this->countPP = 0;
	this->countPPP = 0;
	this->countEnemyShips = 10;
	this->wins = wins;
	this->type = type;
	this->name = name;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			isHitted[i][j] = false;
			}
	}
	newPtrMat.clear();
	enemyM.clearTable();
	matrix.clearTable();
	lastx = -1, lasty = -1;
	isLastHitted = false;
	isLastKilled = false;
}