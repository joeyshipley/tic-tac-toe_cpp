#ifndef __tic_tac_toe_cpp__Engine__
#define __tic_tac_toe_cpp__Engine__

#include <iostream>
#include "DTO.h"

class Engine
{
    public:
        virtual ~Engine() {}
        virtual void Start() = 0;
        virtual Game * PerformTurn(int input) = 0;
        virtual Game * CurrentState() = 0;
        virtual bool IsGameOver() = 0;
};

#endif /* defined(__tic_tac_toe_cpp__Engine__) */
