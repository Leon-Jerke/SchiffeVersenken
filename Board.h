#pragma once
#ifndef Board_h
#define Board_h
#include <string>
#include <vector>
#include <array>
#include <iostream>
#include "Structs.h"

class Ship;  //forward declaration

class Board
{
public:
	Board();
	~Board() {}
	void drawField();
	bool checkShipPosition(std::shared_ptr<struct_Point> Point, int length, bool dir);
	void clearField();
	//int charToInt(char& input);
	bool setHorizontalVertical();
	void setShips();
	void setShipsRandom();
	void updateField();
	char getPos(std::shared_ptr<struct_Point> point);
	void setPos(std::shared_ptr<struct_Point> point, char& c);
	bool attack(std::shared_ptr<struct_Point> point);
	bool fleetStatus();

private:
	static const int boardSize = 10;
	std::array<std::array<char, boardSize>, boardSize> field;
	std::vector<std::shared_ptr<Ship>> shipList;
};

#endif