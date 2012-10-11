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
    string validation = validator->Check(input, board);
    if(!receivedValidInput(validation))
        return * DTO::BuildGame(board->Cells(), validation);

    performPlayersTurn(input);

    if(shouldPerformComputersTurn())
        performComputersTurn();
    
    return * DTO::BuildGame(board->Cells(), validation, status->Check(board));
}

bool GameEngine::receivedValidInput(string validation)
{
    return validation == Rules::VALID;
}

void GameEngine::performPlayersTurn(int input)
{
    board->Apply(input, Rules::PLAYER);
}

bool GameEngine::shouldPerformComputersTurn()
{
    return status->Check(board) == Rules::NONE;
}

void GameEngine::performComputersTurn()
{
    board->Apply(ai->Next(board), Rules::COMPUTER);
}