#include "Board.h"
#include <iostream>

Board::Board()
{
	field[boardSize][boardSize];
	clearField();
}

void Board::clearField()
{
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			field[i][j] = '*';
		}
	}
}

void Board::drawField()
{
    char t = 'A';
    std::cout << "   |";
    for (int i = 0; i < boardSize; ++i) {
        std::cout << " " << t << " |";
        t++;
    }
    std::cout << std::endl;
    for (int i = 0; i < boardSize+1; ++i) {
        std::cout << "___|";
    }
    std::cout << std::endl;
    for (int i = 0; i < boardSize; ++i) {
        std::cout << " " << i << " |";
        for (int k = 0; k < boardSize; ++k) {
            std::cout << " " << field[k][i] << " |";
        }
        std::cout << std::endl;
        for (int z = 0; z < boardSize+1; ++z) {
            std::cout << "___|";
        }
        std::cout << std::endl;
    }
}

bool Board::addShip(int x, int y, int length, char dir)
{
    if (dir = 'v') //vertical
    {
        for (int i = 0; i < length; ++i) {
            if (field[x][y + i] == 'S') {
                std::cout << "Das Schiff kollidiert mit einem Anderen, bitte setzen Sie es erneut." << std::endl;
                return false;
            }
        }
        if (y + length > boardSize) {
            std::cout << "Das Schiff kann hier nicht platziert werden, bitte beachten Sie die Größe des Schiffes: " << length << std::endl;
            return false;
        }
    }
    else if (dir = 'h')
    {
        for (int i = 0; i < length; ++i) {
            if (field[x + i][y] == 'S') {
                std::cout << "Das Schiff kollidiert mit einem Anderen, bitte setzen Sie es erneut." << std::endl;
                return false;
            }
        }
        if (x + length > boardSize) {
            std::cout << "Das Schiff kann hier nicht platziert werden, bitte beachten Sie die Größe des Schiffes: " << length << std::endl;
            return false;
        }
    }
    else
    {
        std::cout << "Das Schiff kann nur vertikal oder horizontal platziert werden." << std::endl;
        return false;
    }
    
    return true;
}

std::string Board::attack(int x, int y)
{
	return "hit";
}
