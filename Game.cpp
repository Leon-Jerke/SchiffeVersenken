#include "Game.h"
#include "Player.h"
#include <limits>
#include <random>

void Game::run()
{
	std::cout << "Waehle den Schwierigkeitsgrad (1 = einfach, 2 = normal, 3 = schwer): ";
	std::cin >> difficulty;
	player1.init();
	PressXToContinue();
	player2.setComputer(true);
	player2.init();
	bool swap = true;
	while (!player1.gameStatus() && !player2.gameStatus())
	{
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
	if (swap)
	{
		std::cout << "Spieler " << player2.getPlayerId() << " hat gewonnen!" << std::endl;
	}
	else
	{
		std::cout << "Spieler " << player1.getPlayerId() << " hat gewonnen!" << std::endl;
	}
}

void Game::turn(Player& currentP, Player& enemyP)
{
	bool newTarget = false;
	std::shared_ptr<struct_Point> point;
	if (currentP.getComputer())
	{
		switch (difficulty)
		{
		case 1:
			{
				std::random_device randomXY; // obtain a random number from hardware
				std::mt19937 gen2(randomXY()); // seed the generator
				std::uniform_int_distribution<> distr2(0, 9); // define the range

				int tmpX = distr2(gen2);
				int tmpY = distr2(gen2);

				while (!newTarget)
				{
					point = std::make_shared<struct_Point>(tmpX, tmpY);
					if (currentP.checkTarget(point))
					{
						newTarget = true;
					}
				}
				std::cout << "Der Computer attackiert..." << std::endl;
				currentP.fire(enemyP, point);
			}
			break;
		case 2:
			break;
		case 3:
			break;
		}
	}
	else
	{
		std::cout << "Spieler " << currentP.getPlayerId() << " ist an der Reihe" << std::endl;
		currentP.showBoard();
		std::cout << "Wohin willst du schiessen? Gib die Koordinaten ein: ";
		std::string input;
		while (!newTarget)
		{
			std::cin >> input;
			point = std::make_shared<struct_Point>(input);
			if (currentP.checkTarget(point))
			{
				newTarget = true;
			}
			else
			{
				std::cout << "Du hast dort bereits hingeschossen. Versuche eine andere Koordinate.";
			}
		}
		currentP.fire(enemyP, point);
		PressXToContinue();
	}
}

void Game::PressXToContinue()
{
	char input;
	bool check = true;
	std::cout << "Druecke X um fortzufahren: ";
	while (check)
	{
		std::cin >> input;
		switch (input) {
		case 'x':
		case 'X':
			check = false;
			break;
		default: check = true;
		}
	}
	system("cls");
}