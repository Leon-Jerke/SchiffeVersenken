#include "Player.h"
#include "Board.h"

void Player::init()
{
	std::cout << "Gib deinen Namen ein: ";
	std::cin >> playerId;
	playerBoard.drawField();
	std::cout << "Falls alle Shiffe Random gesetzt werden sollen, geben Sie bitte R ein, falls nicht drücken Sie Enter";
	char input;
	std::cin >> input;
	switch (input) {
	case 'r':
	case 'R':
		playerBoard.setShipsRandom();
		break;
	default: playerBoard.setShips();
	}

	
}

void Player::fire(Player& enemy, std::shared_ptr<struct_Point> point)
{
	bool hit = enemy.playerBoard.attack(point);
	char marker;
	if (hit)
	{
		marker = 'X';
	}
	else
	{
		marker = 'O';
	}
	hitBoard.setPos(point, marker);
}

bool Player::checkTarget(std::shared_ptr<struct_Point> point)
{
	if (hitBoard.getPos(point) == '*')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Player::showBoard()
{
	//playerBoard.drawField();
	std::cout << "Hit Board: " << std::endl;
	hitBoard.drawField();
}

bool Player::gameStatus()
{
	return playerBoard.fleetStatus();
}
