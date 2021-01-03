#pragma once
#include <string>
#include <vector>

#ifndef Board_h
#define Board_h

class Ship;  //forward declaration

class Board
{
public:
	Board() {}
	~Board() {}
	void drawField();
	bool addShip(int x, int y, int length, char dir);
	void clearField();
	std::string attack(int x, int y);
private:
	const int boardSize = 10;
	char** field;
	std::vector<Ship&> shipList;
};

#endif