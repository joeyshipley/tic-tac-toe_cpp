#ifndef __tic_tac_toe_cpp__GameEngine__
#define __tic_tac_toe_cpp__GameEngine__

#include <iostream>
#include "Rules.h"
#include "Board.h"
#include "Game.h"
#include "InputValidator.h"
#include "GameStatusAlgorithm.h"

class GameEngine
{
    private:
        Board * board;
        InputValidator * inputValidator;
        GameStatusAlgorithm * gameStatusAlgorithm;
        
    public:
        GameEngine(Board * board, InputValidator * inputValidator, GameStatusAlgorithm * gameStatusAlgorithm);
        void Start();
        Game PerformTurn(int input);
};

#endif /* defined(__tic_tac_toe_cpp__GameEngine__) */
