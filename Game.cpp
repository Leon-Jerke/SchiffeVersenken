#include "Game.h"
#include "Player.h"
#include <limits>
#include <random>

void Game::run()
{
	do {
		std::cout << "Waehle den Schwierigkeitsgrad (1 = sehr leicht, 2 = einfach, 3 = normal, 4 = schwer, 5 = God-Mode, 6 = unmöglich): ";
		if (!(std::cin >> difficulty)) {
			std::cout << "Die Eingabe wurde leider nicht Erkannt, bitte versuchen Sie es erneut!" << std::endl;
			std::cin.clear();
			std::cin.ignore(1);
		}
	} while (difficulty != 1 && difficulty != 2 && difficulty != 3 && difficulty != 4 && difficulty != 5 && difficulty != 6);
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
	std::random_device randomXY; // obtain a random number from hardware
	std::mt19937 gen2(randomXY()); // seed the generator
	std::uniform_int_distribution<> distrSafeHit(0, 4);
	int safeHit = distrSafeHit(gen2);
	std::uniform_int_distribution<> distrCor(0, 9);
	if (currentP.getComputer())
	{
		std::cout << "Der Computer attackiert: " << std::endl;
		switch (difficulty)
		{
		case 1:
			while (!newTarget)
			{
				int tmpX = distrCor(gen2);
				int tmpY = distrCor(gen2);
				point = std::make_shared<struct_Point>(tmpX, tmpY);
				if (currentP.checkTarget(point))
				{
					newTarget = true;
				}
			}
		break;
		case 2:
			while (!newTarget)
			{
				int tmpX = distrCor(gen2);
				int tmpY = distrCor(gen2);
				point = std::make_shared<struct_Point>(tmpX, tmpY);
				if (safeHit == 0) {
					if (currentP.checkTarget(point) && enemyP.wouldHit(point))
					{
						newTarget = true;
					}
				}
				else {
					if (currentP.checkTarget(point))
					{
						newTarget = true;
					}
				}
			}
			break;
		case 3:
			while (!newTarget)
			{
				int tmpX = distrCor(gen2);
				int tmpY = distrCor(gen2);
				point = std::make_shared<struct_Point>(tmpX, tmpY);
				if (safeHit == 0 || safeHit == 1) {
					if (currentP.checkTarget(point) && enemyP.wouldHit(point))
					{
						newTarget = true;
					}
				}
				else {
					if (currentP.checkTarget(point))
					{
						newTarget = true;
					}
				}
			}
			break;
		case 4:
			while (!newTarget)
			{
				int tmpX = distrCor(gen2);
				int tmpY = distrCor(gen2);
				point = std::make_shared<struct_Point>(tmpX, tmpY);
				if (safeHit == 0 || safeHit == 1 || safeHit == 2) {
					if (currentP.checkTarget(point) && enemyP.wouldHit(point))
					{
						newTarget = true;
					}
				}
				else {
					if (currentP.checkTarget(point))
					{
						newTarget = true;
					}
				}
			}
			break;
		case 5:
			while (!newTarget)
			{
				int tmpX = distrCor(gen2);
				int tmpY = distrCor(gen2);
				point = std::make_shared<struct_Point>(tmpX, tmpY);
				if (safeHit != 4) {
					if (currentP.checkTarget(point) && enemyP.wouldHit(point))
					{
						newTarget = true;
					}
				}
				else {
					if (currentP.checkTarget(point))
					{
						newTarget = true;
					}
				}
			}
			break;
		case 6:
			while (!newTarget)
			{
				int tmpX = distrCor(gen2);
				int tmpY = distrCor(gen2);
				point = std::make_shared<struct_Point>(tmpX, tmpY);
				if (currentP.checkTarget(point) && enemyP.wouldHit(point))
				{
					newTarget = true;
				}
			}
			break;
		}
		currentP.fire(enemyP, point);
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
	std::cout << "Gebe X ein um fortzufahren: ";
	while (check)
	{
		std::cin >> input;
		switch (input) {
		case 'x':
		case 'X':
			check = false;
			break;
		case 's':
		case 'S':
			//player1.showBoard();
			check = false;
			break;
		default: check = true;
		}
	}
	system("cls");
}