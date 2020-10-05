#include "Table.h"

using namespace std;


Table::Table() {
	vector <vector <Ship*>> newShips(10);
	for (int i = 0; i < 10; i++) {
		newShips[i].resize(10);
		//this->ptrmat[i] = new Ship * [10];
		for (int j = 0; j < 10; j++) {
			newShips[i][j] = NULL;
			this->matrix[i][j] = 0;
			newShips[i][j] = 0;
			this->matrixInt[i][j] = 0;
		}
	}
	this->ptrmat = newShips;
	this->curShip = 0;
}


void Table::Table::printMatrix() {
	system("cls");
	cout << raw << endl;
	//cout << raw << raw << endl;
	for (int i = 0; i < 10; i++) {
		cout << " " << i << " | ";
		for (int j = 0; j < 10; j++) {
			cout << this->matrix[i][j] << " | ";
		}
		cout << endl;
		//cout << "        " << i << " " << enemyRaw << endl;
	}
}

char Table::getValue(int raw, int col) {
	return this->matrix[raw][col];
}

Ship* Table::getPtr(int raw, int col) {
	return this->ptrmat[raw][col];
}

void Table::changeTable(int y1, int x1) {
	int x11, y11, x12, y12;
	y11 = y1 > 0 ? y1 - 1 : 0;
	x11 = x1 > 0 ? x1 - 1 : x1;
	y12 = y1 < 9 ? y1 + 1 : y1;
	x12 = x1 < 9 ? x1 + 1 : x1;
	for (int i = y11; i <= y12; i++) {
		for (int j = x11; j <= x12; j++)
			this->matrix[i][j] = '.';
	}
	this->matrix[y1][x1] = '1';
}

void Table::changeTable(int y1, int x1, int y2, int x2, int type) {
	int x11, y11, x12, y12;
	y11 = y1 > 0 ? y1 - 1 : y1;
	x11 = x1 > 0 ? x1 - 1 : x1;
	y12 = y2 < 9 ? y2 + 1 : y2;
	x12 = x2 < 9 ? x2 + 1 : x2;
	for (int i = y11; i <= y12; i++) {
		for (int j = x11; j <= x12; j++)
			this->matrix[i][j] = '.';
	}
	if (y2 > y1) {
		for (int i = y1; i <= y2; i++) {
			this->matrix[i][x1] = '1';
			this->matrixInt[i][x1] = 1;
		}
	}
	else for (int i = x1; i <= x2; i++) {
		this->matrix[y1][i] = '1';
		this->matrixInt[y1][i] = 1;
	}
}

vector < vector<Ship*> > Table::getptr() {
	return (this->ptrmat);
}

vector <vector <Ship*>> Table::setPtrMat(int y1, char x1, int y2, char x2, int type) {
	Ship* newsh = new Ship();
	newsh->hp = 4 - type;
	newsh->type = type;
	newsh->x1 = x1; newsh->x2 = x2;newsh->y1 = y1; newsh->y2 = y2;
	newsh->stat = SET;
	if (y2 > y1) {
		for (int i = y1; i <= y2; i++) this->ptrmat[i][(x1 - 'a')] = newsh;
	}
	else for (int i = (x1 - 'a'); i <= (x2 - 'a'); i++) this->ptrmat[y1][i] = newsh;

	this->curShip++;
	return ptrmat;
}


void Table::clearTable() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			this->ptrmat[i][j] = NULL;
			this->matrix[i][j] = 0;
			this->ptrmat[i][j] = 0;
			this->matrixInt[i][j] = 0;
		}
	}
}

void Table::SetEmptyPlaces(int y1, int x1, int y2, int x2) {
	int x11, y11, x12, y12;
	y11 = y1 > 0 ? y1 - 1 : y1;
	x11 = x1 > 0 ? x1 - 1 : x1;
	y12 = y2 < 9 ? y2 + 1 : y2;
	x12 = x2 < 9 ? x2 + 1 : x2;

	for (int i = y11; i <= y12; i++) {
		for (int j = x11; j <= x12; j++)
			this->matrix[i][j] = '#';
	}

}