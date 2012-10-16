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

ConsoleRunner * buildConsoleRunner(IO * io)
{
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
    IO * io = new ConsoleIO();
    ConsoleRunner * runner = buildConsoleRunner(io);

    while(true)
    {
        runner->Go();
        io->Output("Press [anykey] to play again. [CTRL + C] to quit.");
        io->Input();
    }
 
    delete runner;
    return 0;
}