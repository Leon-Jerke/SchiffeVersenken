#pragma once
#ifndef Game_h
#define Game_h
#include "Player.h"

//class Player;    //forward declaration

class Game
{
public:
	Game(Player& p1, Player& p2);
	~Game() {}
	void run();
private:
	std::shared_ptr<Player> player1;
	Player& player2;
};

#endif