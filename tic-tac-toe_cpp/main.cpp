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

ConsoleRunner * buildConsoleRunner()
{
    IO * io = new ConsoleIO();
    Board * board = new ThreeByThreeBoard();
    InputValidator * validator = new PlayerInputValidator();
    GameStatusAlgorithm * status = new GameStatusChecker();
    ComputerAiAlgorithm * ai = new NegaMaxAi(status);
    GameEngine * engine = new GameEngine(board, validator, status, ai);
    ConsoleRunner * runner = new ConsoleRunner(io, engine);

    return runner;
}

int main(int argc, char **argv)
{
    ConsoleRunner * runner = buildConsoleRunner();
    runner->Go();
 
    delete runner;
    return 0;
}