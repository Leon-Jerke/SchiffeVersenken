#include "Ship.h"

Ship::Ship()
{
	sunken = false;
}

bool Ship::shipStatus()
{
	return sunken;
}