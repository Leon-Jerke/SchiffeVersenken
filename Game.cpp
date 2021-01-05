#include "Game.h"
#include "Player.h"

void Game::run()
{
	player1.init();
	player2.init();
	while (!player1.gameStatus() && !player2.gameStatus())
	{
		bool swap = true;
		if (swap)
		{
			turn(player1, player2);
			swap = false;
		}
		else
		{
			turn(player2, player1);
			swap = true;
		}
	}
}

void Game::turn(Player& currentP, Player& enemyP)
{
	std::cout << "Spieler " << currentP.playerId << " ist an der Reihe" << std::endl;
	currentP.showBoard();
	std::cout << "Wohin willst du schiessen? Gib die Koordinaten ein: ";
	std::string input;
	bool newTarget = false;
	std::shared_ptr<struct_Point> point;
	while (!newTarget)
	{
		std::cin >> input;
		point = std::make_shared<struct_Point>(input);
		if (currentP.checkTarget(point))
		{
			newTarget = true;
		}
	}
	currentP.fire(enemyP, point);
}