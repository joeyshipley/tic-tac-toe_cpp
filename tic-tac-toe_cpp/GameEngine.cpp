#include "GameEngine.h"
#include "PlayerInputValidator.h"

GameEngine::GameEngine(Board * board, InputValidator * inputValidator)
{
    this->inputValidator = inputValidator;
    this->board = board;
}

void GameEngine::Start()
{
    board->Initialize();
}

Game GameEngine::PerformTurn(int input)
{
    Game game;

    string inputValidation = inputValidator->Check(input, board);
    if(inputValidation != Rules::VALID)
        return game;

    board->Apply(input, Rules::PLAYER);
    
    return game;
}