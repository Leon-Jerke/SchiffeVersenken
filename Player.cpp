#include "Player.h"
#include "Board.h"

void Player::init()
{
	if (computer)
	{
		playerId = "Computer";
		playerBoard.setShipsRandom();
	}
	else
	{
		std::cout << "Gib deinen Namen ein: ";
		std::cin >> playerId;
		playerBoard.drawField();
		std::cout << "Falls alle Schiffe Random gesetzt werden sollen, geben Sie bitte R ein" 
			<< std::endl 
			<< "Falls Sie die Schiffe selber platzieren wollen, geben Sie einen beliebigen anderen Buchstaben ein: ";
		char input;
		std::cin >> input;
		switch (input) {
		case 'r':
		case 'R':
			playerBoard.setShipsRandom();
			playerBoard.drawField();
			break;
		default: playerBoard.setShips();
		}
	}
}

void Player::fire(Player& enemy, std::shared_ptr<struct_Point> point)
{
	char marker = (enemy.playerBoard.attack(point) ? 'X' : 'O');
	hitBoard.setPos(point, marker);
}

bool Player::wouldHit(std::shared_ptr<struct_Point> point)
{
	return (playerBoard.getPos(point) == 'S');
}

bool Player::checkTarget(std::shared_ptr<struct_Point> point)
{
	return (hitBoard.getPos(point) == '*');
}

void Player::showHitBoard()
{
	std::cout << "Hit Board: " << std::endl << std::endl;
	hitBoard.drawField();
	std::cout << std::endl;
}

void Player::showShipBoard(){
	std::cout << "Schiffsfeld: " << std::endl << std::endl;
	playerBoard.drawField();
	std::cout << std::endl;
}

bool Player::gameStatus()
{
	return playerBoard.fleetStatus();
}

void Player::setPlayerId(std::string& id)
{
	playerId = id;
}

std::string Player::getPlayerId()
{
	return playerId;
}

void Player::setComputer(bool b)
{
	computer = b;
}

bool Player::getComputer()
{
	return computer;
}