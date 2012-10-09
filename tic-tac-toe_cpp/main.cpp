#include <iostream>

#include "GameEngine.h"
#include "Board.h"
#include "ThreeByThreeBoard.h"

int main(int argc, char **argv)
{
    ThreeByThreeBoard threeByThreeBoard;
    std::cout << "isReal: " << threeByThreeBoard.IsRealBoard();
    std::cout << "\n";
    
    Board * board = new ThreeByThreeBoard();
    std::cout << "isReal from Interface: " << board->IsRealBoard();
    std::cout << "\n";

    GameEngine * engine = new GameEngine(board);
    engine->Start();
    
    return 0;
}