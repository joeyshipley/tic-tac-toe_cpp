#ifndef __tic_tac_toe_cpp__GameEngine__
#define __tic_tac_toe_cpp__GameEngine__

#include <iostream>
#include "Engine.h"
#include "Rules.h"
#include "Board.h"
#include "DTO.h"
#include "InputValidator.h"
#include "GameStatusAlgorithm.h"
#include "ComputerAiAlgorithm.h"

using namespace std;

class GameEngine : public Engine
{
    private:
        Board * board;
        InputValidator * validator;
        GameStatusAlgorithm * status;
        ComputerAiAlgorithm * ai;
        
    public:
        GameEngine(Board * board, InputValidator * validator, GameStatusAlgorithm * status, ComputerAiAlgorithm * ai);
        virtual void Start();
        virtual Game * PerformTurn(int input);
        virtual bool IsGameOver();
        virtual Game * CurrentState();

        
    private:
        bool receivedValidInput(string validation);
        void performPlayersTurn(int input);
        bool shouldPerformComputersTurn();
        void performComputersTurn();
};

#endif /* defined(__tic_tac_toe_cpp__GameEngine__) */
