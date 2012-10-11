#include "GameEngine.h"

GameEngine::GameEngine(Board * board, InputValidator * validator, GameStatusAlgorithm * status, ComputerAiAlgorithm * ai)
{
    this->board = board;
    this->validator = validator;
    this->status = status;
    this->ai = ai;
}

void GameEngine::Start()
{
    board->Initialize();
}

Game GameEngine::PerformTurn(int input)
{
    Game game;

    string inputValidation = validator->Check(input, board);
    if(inputValidation != Rules::VALID)
    {
        game.Message = inputValidation;
        return game;
    }
        
    board->Apply(input, Rules::PLAYER);

    string winner = status->Check(board);
    if(winner == Rules::NONE)
    {
        int computerChoice = ai->Next(board);
        board->Apply(computerChoice, Rules::COMPUTER);
        winner = status->Check(board);
    }
    
    return game;
}