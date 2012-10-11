#ifndef __tic_tac_toe_cpp__GameEngine__
#define __tic_tac_toe_cpp__GameEngine__

#include <iostream>
#include "Rules.h"
#include "Board.h"
#include "Game.h"
#include "InputValidator.h"
#include "GameStatusAlgorithm.h"
#include "ComputerAiAlgorithm.h"

class GameEngine
{
    private:
        Board * board;
        InputValidator * validator;
        GameStatusAlgorithm * status;
        ComputerAiAlgorithm * ai;
        
    public:
        GameEngine(Board * board, InputValidator * validator, GameStatusAlgorithm * status, ComputerAiAlgorithm * ai);
        void Start();
        Game PerformTurn(int input);
};

#endif /* defined(__tic_tac_toe_cpp__GameEngine__) */
