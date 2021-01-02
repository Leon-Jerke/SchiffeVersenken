#pragma once
#include <string>
#include <vector>

#ifndef Board_h
#define Board_h

class Ship;

class Board
{
public:
	Board() {}
	~Board() {}
	void drawField();
	void addShip(int x, int y, int length, char dir);
	std::string attack(int x, int y);
private:
	const int boardSize = 10;
	char** field;
	std::vector<Ship&> shipList;
};

#endif