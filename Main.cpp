#include <iostream> 
#include <vector>
#include <memory>
#include <array>
#include "Board.h"
#include "Game.h"
#include "Player.h"

int main() {
    Board p1 = Board();
    Board h1 = Board();
    Player player1 = Player(p1, h1);

    Board p2 = Board();
    Board h2 = Board();
    Player player2 = Player(p2, h2);

    Game game = Game(player1, player2);

    game.run();

    return 0;
}