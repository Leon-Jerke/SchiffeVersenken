#include <iostream> 
#include <vector>
#include <memory>
#include <array>
#include "Board.h"
#include "Structs.h"

int main() {
    auto board = Board();
    board.clearField();
    board.setShips();
    return 0;
}