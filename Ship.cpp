#include "Ship.h"

Ship::Ship(int x, int y, int length, char dir)
{
	sunken = false;
}

bool Ship::shipStatus()
{
	return sunken;
}