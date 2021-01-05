#pragma once
#ifndef Player_h
#define Player_h
#include <memory>
#include <string>
#include "Structs.h"

class Board;

class Player
{
public:
	Player(Board& b1, Board& b2) : playerBoard(b1), hitBoard(b2) {}
	~Player() {}
	void init();
	void fire(Player& enemy, std::shared_ptr<struct_Point> point);
	bool checkTarget(std::shared_ptr<struct_Point> point);
	void showBoard();
	bool gameStatus();
	std::string playerId;
private:
	Board& playerBoard;
	Board& hitBoard;
};

#endif