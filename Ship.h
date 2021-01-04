#pragma once
#ifndef Ship_h
#define Ship_h
#include <iostream>
#include "Structs.h"

class Ship
{
public:
	Ship(std::shared_ptr<struct_Point> Point, int length, bool dir);
	~Ship() {}
	bool shipStatus();
	std::shared_ptr<struct_Point> UpperLeftCoordinates;
	int length;
	bool vertical;

private:
	bool sunken;
};

#endif