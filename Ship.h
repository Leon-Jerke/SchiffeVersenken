#pragma once
#ifndef Ship_h
#define Ship_h

class Ship
{
public:
	Ship(int x, int y, int length, char dir) {}
	~Ship() {}
	bool shipStatus();

private:
	bool sunken;
};

#endif