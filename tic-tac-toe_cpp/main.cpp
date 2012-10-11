#include <iostream>

#include "GameEngine.h"
#include "Board.h"
#include "InputValidator.h"
#include "GameStatusAlgorithm.h"
#include "ComputerAiAlgorithm.h"
#include "ThreeByThreeBoard.h"
#include "PlayerInputValidator.h"
#include "GameStatusChecker.h"
#include "NegaMaxAi.h"

int main(int argc, char **argv)
{
    Board * board = new ThreeByThreeBoard();
    InputValidator * validator = new PlayerInputValidator();
    GameStatusAlgorithm * status = new GameStatusChecker();
    ComputerAiAlgorithm * ai = new NegaMaxAi(status);
    
    GameEngine engine = * new GameEngine(board, validator, status, ai);
    
    engine.Start();
    
    Game response1 = engine.PerformTurn(1);
    Game response2 = engine.PerformTurn(2);
    
    delete board;
    delete validator;
    delete status;
    delete ai;
    
    return 0;
}