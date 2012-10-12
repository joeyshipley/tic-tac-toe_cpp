#include <iostream>

#include "ConsoleRunner.h"
#include "IO.h"
#include "ConsoleIO.h"
#include "GameEngine.h"
#include "Board.h"
#include "InputValidator.h"
#include "GameStatusAlgorithm.h"
#include "ComputerAiAlgorithm.h"
#include "ThreeByThreeBoard.h"
#include "PlayerInputValidator.h"
#include "GameStatusChecker.h"
#include "NegaMaxAi.h"

using namespace std;

int main(int argc, char **argv)
{
    IO * io = new ConsoleIO();
    Board * board = new ThreeByThreeBoard();
    InputValidator * validator = new PlayerInputValidator();
    GameStatusAlgorithm * status = new GameStatusChecker();
    ComputerAiAlgorithm * ai = new NegaMaxAi(status);
    GameEngine * engine = new GameEngine(board, validator, status, ai);
    ConsoleRunner * runner = new ConsoleRunner(io, engine);

    runner->Go();
    
    delete io;
    delete board;
    delete validator;
    delete status;
    delete ai;
    delete engine;
    delete runner;
    
    return 0;
}