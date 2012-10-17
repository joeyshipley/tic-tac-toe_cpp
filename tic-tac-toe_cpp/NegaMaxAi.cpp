#include "NegaMaxAi.h"
#include "Cell.h"
#include "Rules.h"

NegaMaxAi::NegaMaxAi(GameStatusAlgorithm * status)
{
    this->status = status;
}

int NegaMaxAi::Next(Board * board)
{
    highestMove = 0;
    highestScore = -MAX_SCORE;

    vector<Cell> availableMoves = board->AvailableMoves();
    for(int i = 0; i < availableMoves.size(); i++)
    {
        int move = availableMoves[i].Value;
        int score = negamax(board, move, MAX_DEPTH, Rules::COMPUTER, 1);
        calculateBestScore(move, score);
    }

    return highestMove;
};

void NegaMaxAi::calculateBestScore(int move, int score)
{
    if(score > highestScore)
    {
        highestMove = move;
        highestScore = score;
    }
}

int NegaMaxAi::scoreMove(int depth, string winner)
{
    if(winner == Rules::COMPUTER_WON)
        return 1 * depth;
        
    if(winner == Rules::PLAYER_WON)
        return -1 * depth;
        
    return 0;
}

string NegaMaxAi::opponent(string current)
{
    return current == Rules::PLAYER ? Rules::COMPUTER : Rules::PLAYER;
}

int NegaMaxAi::negamax(Board * board, int move, int depth, string owner, int negamod)
{
    Board * copy = board->Clone();
    copy->Apply(move, owner);
    string winner = status->Check(copy);
    
    if(winner != Rules::INPROGRESS)
    {
        delete copy;
        return scoreMove(depth, winner);
    }

    int bestScore = MAX_SCORE * negamod;
    vector<Cell> availableMoves = copy->AvailableMoves();
    for(int i = 0; i < availableMoves.size(); i++)
    {
        int score = negamax(copy, availableMoves[i].Value, depth - 1, opponent(owner), -negamod);
        if(score * negamod < bestScore * negamod)
            bestScore = score;
    }

    delete copy;
    return bestScore;
}