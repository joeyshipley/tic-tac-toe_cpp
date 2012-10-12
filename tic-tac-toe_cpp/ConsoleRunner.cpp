#include "ConsoleRunner.h"

ConsoleRunner::ConsoleRunner(IO * io, Engine * engine)
{
    this->io = io;
    this->engine = engine;
    this->formatter = new ResponseFormatter();
}

void ConsoleRunner::Go()
{
    engine->Start();

    Game * game = engine->CurrentState();
    displayBoard(game);
    
    while(!engine->IsGameOver())
        game = loop();
        
    displayGameOver(game);
}

Game * ConsoleRunner::loop()
{
    askForInput();
    int input = io->Input();
    displayComputerIsThinking();
    Game * game = engine->PerformTurn(input);
    displayBoard(game);
    displayValidation(game);

    return game;
}

void ConsoleRunner::askForInput()
{
    io->Output(formatter->AskForInput());
}

void ConsoleRunner::displayComputerIsThinking()
{
    io->Output(formatter->Thinking());
}

void ConsoleRunner::displayBoard(Game * game)
{
    io->Output(formatter->DisplayTicTacToe(game));
}

void ConsoleRunner::displayValidation(Game * game)
{
    io->Output(formatter->FormatValidation(game->Message));
}

void ConsoleRunner::displayGameOver(Game * game)
{
    io->Output(formatter->GameOver(game->Winner));
}