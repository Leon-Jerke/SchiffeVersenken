#include "Board.h"
#include "Ship.h"
#include <iostream>
#include <memory>
#include <time.h>
Board::Board()
{
	clearField();
}

void Board::clearField()
{
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			field[i][j] = '*';
		}
	}
}

void Board::drawField()
{
	char t = 'A';
	std::cout << "   |";
	for (int i = 0; i < boardSize; ++i) {
		std::cout << " " << t << " |";
		t++;
	}
	std::cout << std::endl;
	for (int i = 0; i < boardSize + 1; ++i) {
		std::cout << "___|";
	}
	std::cout << std::endl;
	for (int i = 0; i < boardSize; ++i) {
		std::cout << " " << i << " |";
		for (int k = 0; k < boardSize; ++k) {
			std::cout << " " << field[k][i] << " |";
		}
		std::cout << std::endl;
		for (int z = 0; z < boardSize + 1; ++z) {
			std::cout << "___|";
		}
		std::cout << std::endl;
	}
}

bool Board::checkShipPosition(std::shared_ptr<struct_Point> Point, int length, bool dir)
{
	if (dir) //vertical
	{
		if (Point->y + length > boardSize) {
			return false;
		}
		for (int i = 0; i < length; ++i) { //this field
			if (field[Point->x][Point->y + i] == 'S') {

				return false;
			}
			if (Point->y + i < boardSize - 1) {
				if (field[Point->x][Point->y + i + 1] == 'S') { //lower field

					return false;
				}
			}
			if (Point->y + i > 0) {
				if (field[Point->x][Point->y + i - 1] == 'S') { //upper field

					return false;
				}
			}
			if (Point->x < boardSize - 1) {
				if (field[Point->x + 1][Point->y + i] == 'S') { //right field

					return false;
				}
			}
			if (Point->x > 0) {
				if (field[Point->x - 1][Point->y + i] == 'S') { //left field

					return false;
				}
			}
		}
	}
	else
	{
		if (Point->x + length > boardSize) {
			return false;
		}
		for (int i = 0; i < length; ++i) {
			if (field[Point->x + i][Point->y] == 'S') { //this field
				return false;
			}
			if (Point->x + i < boardSize - 1) {
				if (field[Point->x + i + 1][Point->y] == 'S') { // right field
					return false;
				}
			}
			if (Point->x + i > 0) {
				if (field[Point->x + i - 1][Point->y] == 'S') { // left field
					return false;
				}
			}
			if (Point->y < boardSize - 1) {
				if (field[Point->x + i][Point->y + 1] == 'S') { //lower field
					return false;
				}
			}
			if (Point->y > 0) {
				if (field[Point->x + i][Point->y - 1] == 'S') { //upper field
					return false;
				}
			}
		}
	}
	return true;
}


bool Board::setHorizontalVertical() {
	char input;
	do {
		std::cout << "Gebe \"H\" f\x81r Horizontal und \"V\" f\x81r Vertikal ein" << std::endl;
		std::cin >> input;
		switch (input) {
		case 'h':
		case 'H':
			return false;
		case 'v':
		case 'V':
			return true;
		default: std::cout << "Die Eingabe wurde leider nicht erkannt, versuche es bitte erneut" << std::endl;;
		}
	} while (true);
}

void Board::setShips() {
	std::string input;
	int tmpX;
	int tmpY;
	bool tmpDirection;
	int tmpSize;
	bool inputCheck = true;
	for (int i = 1; i < 11; ++i) {
		switch (i) {
		case 1:
			tmpSize = 5;
			break;
		case 2:
			tmpSize = 4;
			break;
		case 4:
			tmpSize = 3;
			break;
		case 7:
			tmpSize = 2;
			break;
		}
		while (inputCheck) {
			std::cout << "Um Schiff " << i << " der Gr\x94\xE1\e " << tmpSize << " zu setzen, muessen Sie festlegen ob dieses Horizontal oder Vertikal gesetzt werden soll." << std::endl;
			tmpDirection = setHorizontalVertical();
			std::cout << "Nun benoetige ich " << (tmpDirection ? " die oberste " : " die linkeste ") << "Koordinaten des Schiffes" << std::endl;
			std::cout << "Bitte beachten Sie die Gr\x94\xE1\e des Schiffes von " << tmpSize << " Feldern" << std::endl;
			std::cout << "Koordinaten: ";
			std::cin >> input;
			if (input.size() == 2) {
				inputCheck = false;
			}
			else{
				std::cout << "Fehlerhafte Eingabe, bitte versuche es erneut!" << std::endl;
			}
		}
		auto point = std::make_shared<struct_Point>(input);
		if (checkShipPosition(point, tmpSize, tmpDirection)) {
			auto newShip = std::make_shared<Ship>(Ship(point, tmpSize, tmpDirection));
			shipList.push_back(newShip);
			updateField();
			drawField();
		}
		else {
			std::cout << "Das Schiff kollidiert mit einem Anderen oder dem Spielfeldrand, bitte setze es erneut." << std::endl;
			i--;
		}
	}
}

void Board::setShipsRandom() {
	bool tmpDirection;
	int tmpSize;
	int tmpX;
	int tmpY;
	srand((unsigned)time(NULL));

	for (int i = 1; i < 11; ++i) {
		switch (i) {
		case 1:
			tmpSize = 5;
			break;
		case 2:
			tmpSize = 4;
			break;
		case 4:
			tmpSize = 3;
			break;
		case 7:
			tmpSize = 2;
			break;
		}

		tmpDirection = (rand() % 9 < 5);
		tmpX = rand() % 9;
		tmpY = rand() % 9;

		auto point = std::make_shared<struct_Point>(tmpX, tmpY);
		if (checkShipPosition(point, tmpSize, tmpDirection)) {
			auto newShip = std::make_shared<Ship>(Ship(point, tmpSize, tmpDirection));
			shipList.push_back(newShip);
			updateField();
		}
		else {
			i--;
		}
	}
	

}

void Board::updateField() {
	int size;
	for (std::shared_ptr<Ship> tmp : shipList) {
		if (tmp->vertical) {
			for (int i = 0; i < tmp->length; ++i) {
				field[tmp->UpperLeftCoordinates->x][tmp->UpperLeftCoordinates->y + i] = 'S';
			}
		}
		else {
			for (int i = 0; i < tmp->length; ++i) {
				field[tmp->UpperLeftCoordinates->x + i][tmp->UpperLeftCoordinates->y] = 'S';
			}
		}
	}

}

char Board::getPos(std::shared_ptr<struct_Point> point)
{
	return field[point->x][point->y];
}

void Board::setPos(std::shared_ptr<struct_Point> point, char& c)
{
	field[point->x][point->y] = c;
}

bool Board::attack(std::shared_ptr<struct_Point> point)
{
	char target = field[point->x][point->y];
	char tmpChar = 'A' + point->x;
	if (target == 'S')
	{
		field[point->x][point->y] = 'X';
		std::cout << "Treffer! Auf " << tmpChar << point->y << std::endl;
		for (std::shared_ptr<Ship> tmp : shipList) {
			if (tmp->vertical) {
				for (int i = 0; i < tmp->length; ++i) {
					if (tmp->UpperLeftCoordinates->x == point->x && tmp->UpperLeftCoordinates->y + i == point->y)
					{
						if (tmp->shipHit())
						{
							std::cout << "Schiff versenkt!" << std::endl;
						}
					}
				}
			}
			else {
				for (int i = 0; i < tmp->length; ++i) {
					if (tmp->UpperLeftCoordinates->x + i == point->x && tmp->UpperLeftCoordinates->y == point->y)
					{
						if (tmp->shipHit())
						{
							std::cout << "Schiff versenkt!" << std::endl;
						}
					}
				}
			}
		}
		return true;
	}
	else
	{
		std::cout << "Nicht Getroffen! Auf " << tmpChar << point->y << std::endl;
		return false;
	}
}

bool Board::fleetStatus()
{
	bool won = true;
	for (std::shared_ptr<Ship> tmp : shipList)
	{
		if (!tmp->sunken)
		{
			won = false;
		}
	}
	return won;
}