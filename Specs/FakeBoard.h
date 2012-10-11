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
        virtual void Initialize(vector<Cell> cells);
        virtual void Apply(int input, string owner);
        virtual vector<Cell> Cells();
        virtual Cell FindCell(int value);
        virtual Cell FindCellByCoordinates(int x, int y);
        virtual bool HasAvailableMoves();
        virtual vector<Cell> AvailableMoves();
        virtual Board * Clone();
        
    private:
        Cell returnsFromFindCellCall;
        
    public:
        FakeBoard();
        void AndReturnsFromFindCell(Cell cell);
        int InitializedTimesCalled;
        int ApplyTimesCalled;
};

#endif /* defined(__tic_tac_toe_cpp__FakeBoard__) */
