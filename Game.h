#pragma once
#ifndef Game_h
#define Game_h

class Player;    //forward declaration

class Game
{
public:
	Game(Player& p1, Player& p2) : player1(p1), player2(p2), difficulty(1) {}
	~Game() {}
	void run();
	void turn(Player& currentP, Player& enemyP);
	void PressAnyKeyToContinue();
private:
	Player& player1;
	Player& player2;
	int difficulty;
};

#endif