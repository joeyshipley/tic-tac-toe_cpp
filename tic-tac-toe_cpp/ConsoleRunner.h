#ifndef __tic_tac_toe_cpp__ConsoleRunner__
#define __tic_tac_toe_cpp__ConsoleRunner__

#include <iostream>
#include "IO.h"
#include "ResponseFormatter.h"
#include "Engine.h"

class ConsoleRunner
{
    private:
        IO * io;
        ResponseFormatter * formatter;
        Engine * engine;
        
    public:
        ConsoleRunner(IO * io, Engine * engine);
        void Go();
        
    private:
        Game * loop();
        void askForInput();
        void displayBoard(Game * game);
        void displayComputerIsThinking();
        void displayValidation(Game * game);
        void displayGameOver(Game * game);
};

#endif /* defined(__tic_tac_toe_cpp__ConsoleRunner__) */
