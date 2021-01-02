#pragma once
#ifndef Ship_h
#define Ship_h

class Ship
{
public:
	Ship() {}
	~Ship() {}
	bool shipStatus();

private:
	bool sunken;
};

#endif