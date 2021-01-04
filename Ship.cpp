#include "Ship.h"
#include <iostream>

Ship::Ship(std::shared_ptr<struct_Point> Point, int length, bool dir)
{
	sunken = false;
	UpperLeftCoordinates = Point;
	this->length = length;
	vertical = dir;
}

bool Ship::shipStatus()
{
	return sunken;
}
