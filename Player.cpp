#include "Player.h"
#include "Board.h"

void Player::init()
{
	playerBoard.drawField();
	playerBoard.setShips();
}

void Player::fire(Player& enemy, std::shared_ptr<struct_Point> point)
{
	
}
