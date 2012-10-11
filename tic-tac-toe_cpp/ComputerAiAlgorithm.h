#ifndef __tic_tac_toe_cpp__ComputerAiAlgorithm__
#define __tic_tac_toe_cpp__ComputerAiAlgorithm__

#include <iostream>
#include "Board.h"

class ComputerAiAlgorithm
{
    public:
        virtual int Next(Board * board) = 0;
};

#endif /* defined(__tic_tac_toe_cpp__ComputerAiAlgorithm__) */
