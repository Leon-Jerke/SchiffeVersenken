﻿#include "Board.h"
#include "Ship.h"
#include <iostream>
#include <memory>



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
			std::cout << "Das Schiff kann hier nicht platziert werden, bitte beachten Sie die Gr��e des Schiffes: " << length << std::endl;
			return false;
		}
		for (int i = 0; i < length; ++i) { //this field
			if (field[Point->x][Point->y + i] == 'S') {
				std::cout << "Das Schiff kollidiert mit einem Anderen, bitte setzen Sie es erneut." << std::endl;
				return false;
			}
			if (Point->y + i < boardSize - 1) {
				if (field[Point->x][Point->y + i + 1] == 'S') { //lower field
					std::cout << "Das Schiff kollidiert mit einem Anderen, bitte setzen Sie es erneut." << std::endl;
					return false;
				}
			}
			if (Point->y + i > 0) {
				if (field[Point->x][Point->y + i - 1] == 'S') { //upper field
					std::cout << "Das Schiff kollidiert mit einem Anderen, bitte setzen Sie es erneut." << std::endl;
					return false;
				}
			}
			
			if (Point->x < boardSize - 1) {
				if (field[Point->x + 1][Point->y + i] == 'S') { //right field
					std::cout <<
						"Das Schiff kollidiert mit einem Anderen, bitte setzen Sie es erneut." << std::endl;
					return false;
				}
			}
			if (Point->x < 0) {
				if (field[Point->x - 1][Point->y + i] == 'S') { //left field
					std::cout << "Das Schiff kollidiert mit einem Anderen, bitte setzen Sie es erneut." << std::endl;
					return false;
				}
			}
			
		}

	}
	else
	{

		if (Point->x + length > boardSize) {
			std::cout << "Das Schiff kann hier nicht platziert werden, bitte beachten Sie die Größe des Schiffes: " << length << std::endl;
			return false;
		}
		for (int i = 0; i < length; ++i) {
			if (field[Point->x + i][Point->y] == 'S') { //this field
				std::cout << "Das Schiff kollidiert mit einem Anderen, bitte setzen Sie es erneut." << std::endl;
				return false;
			}
			if (Point->x + i < boardSize - 1) {
				if (field[Point->x + i + 1][Point->y] == 'S') { // right field
					std::cout << "Das Schiff kollidiert mit einem Anderen, bitte setzen Sie es erneut." << std::endl;
					return false;
				}
			}
			
			if (Point->x + i> 0) {
				if (field[Point->x + i - 1][Point->y] == 'S') { // left field
					std::cout << "Das Schiff kollidiert mit einem Anderen, bitte setzen Sie es erneut." << std::endl;
					return false;
				}
			}
			
			if (Point->y < boardSize - 1) {
				if (field[Point->x + i][Point->y + 1] == 'S') { //lower field
					std::cout << "Das Schiff kollidiert mit einem Anderen, bitte setzen Sie es erneut." << std::endl;
					return false;
				}
			}

			if (Point->y > 0) {
				if (field[Point->x + i][Point->y - 1] == 'S') { //upper field
					std::cout << "Das Schiff kollidiert mit einem Anderen, bitte setzen Sie es erneut." << std::endl;
					return false;
				}
			}
			
		}
	}
	// else
	// {
	//     std::cout << "Das Schiff kann nur vertikal oder horizontal platziert werden." << std::endl;
	//     return false;
	// }

	return true;
}

//int Board::charToInt(char& input) {
//	switch (input) {
//	case 'a':
//	case 'A':
//	case '0':
//		return 0;
//	case 'b':
//	case 'B':
//	case '1':
//		return 1;
//	case 'c':
//	case 'C':
//	case '2':
//		return 2;
//	case 'd':
//	case 'D':
//	case '3':
//		return 3;
//	case 'e':
//	case 'E':
//	case '4':
//		return 4;
//	case 'f':
//	case 'F':
//	case '5':
//		return 5;
//	case 'g':
//	case 'G':
//	case '6':
//		return 6;
//	case 'h':
//	case 'H':
//	case '7':
//		return 7;
//	case 'i':
//	case 'I':
//	case '8':
//		return 8;
//	case 'j':
//	case 'J':
//	case '9':
//		return 9;
//	default:
//		return 0;
//	}
//}

bool Board::setHorizontalVertical() {
	char input;
	std::cout << "Geben Sie \"H\" für Horizontal und \"V\" für Vertikal ein" << std::endl;
	std::cin >> input;
	switch (input) {
	case 'h':
	case 'H':
		return false;
	case 'v':
	case 'V':
		return true;
	default: std::cout << "Die Eingabe wurde leider nicht erkannt, versuchen Sie es bitte erneut";
	}
}

void Board::setShips() {
	std::string input;
	int tmpX;
	int tmpY;
	bool tmpDirection;
	int tmpSize;
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
		std::cout << "Um Schiff " << i << " der Größe " << tmpSize << " zu setzen, muessen Sie festlegen ob dieser Horizontal oder Vertikal gesetzt werden soll." << std::endl;
		tmpDirection = setHorizontalVertical();
		std::cout << "Nun benötige ich " << (tmpDirection ? " die oberste " : " die linkeste ") << "Koordinate des Schiffes" << std::endl;
		std::cout << "Bitte beachten Sie die jeweilige Größe des Schiffes von" << tmpSize << "Feldern" << std::endl;
		std::cout << "Koordinaten: ";
		std::cin >> input;
		//std::cin >> input;
		//tmpX = charToInt(input);
		//std::cout << std::endl << "Y: ";
		//std::cin >> input;
		//tmpY = input - '0';
		auto point = std::make_shared<struct_Point>(input);
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
	drawField();
}

std::string Board::attack(std::shared_ptr<struct_Point> point)
{
	char target = field[point->x][point->y];
	if (target == 'S')
	{

		return "hit";
	}
	else
	{
		return "Missed!";
	}
}