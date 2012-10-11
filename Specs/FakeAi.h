#ifndef __tic_tac_toe_cpp__FakeAi__
#define __tic_tac_toe_cpp__FakeAi__

#include <iostream>
#include "ComputerAiAlgorithm.h"
#include "Board.h"

class FakeAi : public ComputerAiAlgorithm
{
    public:
        virtual int Next(Board * board);
        
    public:
        FakeAi();
        int NextTimesCalled;
        void AndReturnsForNext(int value);

    private:
        int returnForNext;
};

#endif /* defined(__tic_tac_toe_cpp__FakeAi__) */
