#include "Game.h"
#include "Player.h"
#include <time.h>

void Game::run()
{
	std::cout << "Willkomen zu Schiffe Versenken!"
		<< std::endl
		<< "Ein Projekt von Paul Burkard, Leon Jerke und Ruben Herbstreuth"
		<< std::endl 
		<< std::endl
		<< "**************************************************************" 
		<< std::endl
		<< std::endl;
	
	do {
		std::cout << "Waehle den Schwierigkeitsgrad (1 = sehr leicht, 2 = normal, 3 = schwer, 4 = God-Mode): ";
		if (!(std::cin >> difficulty)) {
			std::cout << std::endl << "Die Eingabe wurde leider nicht Erkannt, bitte versuchen Sie es erneut!" << std::endl;
			std::cin.clear();
			std::cin.ignore(1);
		}
	} while (difficulty != 1 && difficulty != 2 && difficulty != 3 && difficulty != 4);
	std::cout << std::endl;
	player1.init();
	PressAnyKeyToContinue();
	player2.setComputer(true);
	player2.init();
	bool swap = true;
	while (!player1.gameStatus() && !player2.gameStatus())
	{
		if (swap)
		{
			turn(player1, player2);
			swap = false;
			PressAnyKeyToContinue();
		}
		else
		{
			turn(player2, player1);
			swap = true;
			PressAnyKeyToContinue();
		}
	}
	if (swap)
	{
		std::cout << "******************************************************" << std::endl << std::endl;
		std::cout << "Spieler " << player2.getPlayerId() << " hat gewonnen!" << std::endl;
		std::cout << "******************************************************" << std::endl << std::endl;
	}
	else
	{
		std::cout << "******************************************************" << std::endl << std::endl;
		std::cout << "Spieler " << player1.getPlayerId() << " hat gewonnen!" << std::endl;
		std::cout << "******************************************************" << std::endl << std::endl;
	}
}

void Game::turn(Player& currentP, Player& enemyP)
{
	bool newTarget = false;
	std::shared_ptr<struct_Point> point;
	srand((unsigned)time(NULL)); // Seed the gerenator
	int safeHit = rand() % 99;
	if (currentP.getComputer())
	{
		std::cout << "Der Computer attackiert: " << std::endl;
		switch (difficulty)
		{
		case 1:
			while (!newTarget)
			{
				int tmpX = rand() % 9;
				int tmpY = rand() % 9;
				point = std::make_shared<struct_Point>(tmpX, tmpY);
				if (currentP.checkTarget(point))
				{
					newTarget = true;
				}
			}
		break;
		case 2:
			if(!player2.gameStatus()){
				if(safeHit < 30){
					for(int i = 0; i < 10; ++i){
						for(int k = 0; k < 10; ++k){
							point = std::make_shared<struct_Point>(i,k);
							if (currentP.checkTarget(point) && enemyP.wouldHit(point))
							{
								newTarget = true;
								break;
							}
						}
						if(newTarget){
							break;
						}
					}
				}
				else{
					while (!newTarget)
					{
						int tmpX = rand() % 9;
						int tmpY = rand() % 9;
						point = std::make_shared<struct_Point>(tmpX, tmpY);
						if (currentP.checkTarget(point))
						{
							newTarget = true;
						}
					}
				}
			}
			break;
		case 3:
			if(!player2.gameStatus()){
				if(safeHit < 60){
					for(int i = 0; i < 10; ++i){
						for(int k = 0; k < 10; ++k){
							point = std::make_shared<struct_Point>(i,k);
							if (currentP.checkTarget(point) && enemyP.wouldHit(point))
							{
								newTarget = true;
								break;
							}
						}
						if(newTarget){
							break;
						}
					}
				}
				else{
					while (!newTarget)
					{
						int tmpX = rand() % 9;
						int tmpY = rand() % 9;
						point = std::make_shared<struct_Point>(tmpX, tmpY);
						if (currentP.checkTarget(point))
						{
							newTarget = true;
						}
					}
				}
			}
			break;
		case 4:
			if(!player2.gameStatus()){
				for(int i = 0; i < 10; ++i){
					for(int k = 0; k < 10; ++k){
						point = std::make_shared<struct_Point>(i,k);
						if (currentP.checkTarget(point) && enemyP.wouldHit(point))
						{
							newTarget = true;
							break;
						}
					}
					if(newTarget){
						break;
					}
				}
			}
			break;
		}
		currentP.fire(enemyP, point);
		enemyP.showShipBoard();
	}
	else
	{
		std::cout << "Spieler " << currentP.getPlayerId() << " ist an der Reihe" << std::endl;
		currentP.showHitBoard();
		std::string input;
		while (!newTarget)
		{
			bool inputCheck = true;
			while(inputCheck){
				std::cout << "Wohin willst du schiessen? Gib die Koordinaten ein: ";
				std::cin >> input;
				if (input.size() == 2) {
					inputCheck = false;
				}
				else{
					std::cout << std::endl << "Fehlerhafte Eingabe, bitte versuche es erneut!" << std::endl;
				}
			}
			point = std::make_shared<struct_Point>(input);
			if (currentP.checkTarget(point))
			{
				newTarget = true;
			}
			else
			{
				std::cout << std::endl << "Du hast dort bereits hingeschossen. Versuche eine andere Koordinate.";
			}
		}
		currentP.fire(enemyP, point);
	}
}

void Game::PressAnyKeyToContinue()
{
	system("pause"); 	// system("read"); auf OS X laut: https://stackoverflow.com/a/1452701/12977913
						// system("pause"); auf Windows
	system("cls"); 	// system("clear"); auf OS X laut: https://stackoverflow.com/questions/27616522/cannot-use-systemcls-in-xcode-in-mac
						// system(cls); auf Windows
}
	