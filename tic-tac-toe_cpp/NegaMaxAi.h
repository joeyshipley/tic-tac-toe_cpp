#ifndef __tic_tac_toe_cpp__NegaMaxAi__
#define __tic_tac_toe_cpp__NegaMaxAi__

#include <iostream>
#include "ComputerAiAlgorithm.h"
#include "GameStatusAlgorithm.h"
#include "Board.h"

using namespace std;

class NegaMaxAi : public ComputerAiAlgorithm
{
    public:
        NegaMaxAi(GameStatusAlgorithm * status);
        virtual ~NegaMaxAi() {}
        virtual int Next(Board * board);
        const float MAX_SCORE = 999999;
        const int MAX_DEPTH = 9;
        
    private:
        GameStatusAlgorithm * status;
        int highestMove;
        int highestScore;
        int scoreMove(int depth, string winner);
        void calculateBestScore(int move, int score);
        string opponent(string current);
        int negamax(Board * board, int move, int depth, string owner, int negamod);
};

#endif /* defined(__tic_tac_toe_cpp__NegaMaxAi__) */
