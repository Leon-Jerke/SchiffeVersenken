#pragma once
#ifndef Player_h
#define Player_h
#include <memory>

class Board;

class Player
{
public:
	Player();
	~Player() {}
	void fire(int x, int y);
private:
	std::shared_ptr<Board> playerBoard;
	std::shared_ptr<Board> hitBoard;
};

#endif