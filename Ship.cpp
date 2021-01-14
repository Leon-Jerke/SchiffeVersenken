#include "Ship.h"
#include <iostream>
#include <memory>

Ship::Ship(std::shared_ptr<struct_Point> Point, int length, bool dir)
{
	sunken = false;
	UpperLeftCoordinates = Point;
	this->length = length;
	vertical = dir;
	health = length;
}

bool Ship::shipHit()
{
	health--;
	if (health > 0)
	{
		return sunken;
	}
	else
	{
		sunken = true;
		return sunken;
	}
}
