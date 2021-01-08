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
	Player(Board& b1, Board& b2) : playerBoard(b1), hitBoard(b2), computer(false) {}
	~Player() {}
	void init();
	void fire(Player& enemy, std::shared_ptr<struct_Point> point);
	bool checkTarget(std::shared_ptr<struct_Point> point);
	void showBoard();
	bool gameStatus();
	void setPlayerId(std::string& id);
	std::string getPlayerId();
	void setComputer(bool b);
	bool getComputer();
private:
	std::string playerId;
	bool computer;
	Board& playerBoard;
	Board& hitBoard;
};

#endif