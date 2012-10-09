#include <iostream>

#include "GameEngine.h"
#include "Board.h"
#include "ThreeByThreeBoard.h"

int main(int argc, char **argv)
{
    Board * board = new ThreeByThreeBoard();
    GameEngine engine = * new GameEngine(board);
    
    engine.Start();
    engine.PerformTurn(1);
    engine.PerformTurn(2);
    
    delete board;
    
    return 0;
}