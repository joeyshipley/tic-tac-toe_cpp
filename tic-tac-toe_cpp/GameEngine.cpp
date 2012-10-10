#include "GameEngine.h"
#include "PlayerInputValidator.h"

GameEngine::GameEngine(Board * board, InputValidator * inputValidator, GameStatusAlgorithm * gameStatusAlgorithm)
{
    this->board = board;
    this->inputValidator = inputValidator;
    this->gameStatusAlgorithm = gameStatusAlgorithm;
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

    string winner = gameStatusAlgorithm->Check(board);
    
    return game;
}