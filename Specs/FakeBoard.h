#ifndef __tic_tac_toe_cpp__FakeBoard__
#define __tic_tac_toe_cpp__FakeBoard__

#include <iostream>
#include "Board.h"
#include "Cell.h"

class FakeBoard : public Board
{
    public:
        virtual ~FakeBoard();
        virtual void Initialize();
        virtual void Apply(int input, string owner);
        virtual vector<Cell> Cells();
        virtual Cell FindCell(int value);
        
    public:
        FakeBoard();
        int InitializedTimesCalled;
        int ApplyTimesCalled;
};

#endif /* defined(__tic_tac_toe_cpp__FakeBoard__) */
