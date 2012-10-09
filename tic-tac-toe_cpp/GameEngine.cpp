#include "GameEngine.h"

GameEngine::GameEngine(Board * board)
{
    this->board = board;
}

void GameEngine::Start()
{
    std::cout << "From private board, isReal: " << this->board->IsRealBoard();
}