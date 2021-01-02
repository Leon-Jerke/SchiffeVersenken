#pragma once
#ifndef Player_h
#define Player_h

class Board;

class Player
{
public:
	Player() {}
	~Player() {}
	void fire(int x, int y);
private:
	Board& playerBoard;
	Board& hitBoard;
};

#endif