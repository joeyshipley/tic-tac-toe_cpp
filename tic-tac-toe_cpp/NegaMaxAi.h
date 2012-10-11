#ifndef __tic_tac_toe_cpp__NegaMaxAi__
#define __tic_tac_toe_cpp__NegaMaxAi__

#include <iostream>
#include "ComputerAiAlgorithm.h"
#include "Board.h"

class NegaMaxAi : public ComputerAiAlgorithm
{
    public:
        virtual int Next(Board * board);
};

#endif /* defined(__tic_tac_toe_cpp__NegaMaxAi__) */
