#include "GameEngine.h"
#include "Rules.h"

GameEngine::GameEngine(Board * board)
{
    this->board = board;
}

void GameEngine::Start()
{
    board->Initialize();
}

Game GameEngine::PerformTurn(int input)
{
    board->Apply(input, Rules::PLAYER);
    
    Game game;
    return game;
}