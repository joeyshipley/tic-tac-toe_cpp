#ifndef __tic_tac_toe_cpp__ThreeByThreeBoard__
#define __tic_tac_toe_cpp__ThreeByThreeBoard__

#include <iostream>
#include <vector>
#include "Rules.h"
#include "Board.h"
#include "Cell.h"

class ThreeByThreeBoard : public Board
{
    private:
        vector<Cell> cells;

    public:
        virtual ~ThreeByThreeBoard();
        virtual void Initialize();
        virtual void Apply(int input, string owner);
        virtual vector<Cell> Cells();
        virtual Cell FindCell(int value);
        virtual Cell FindCellByCoordinates(int x, int y);
        virtual bool HasAvailableMoves();
        
    private:
        Cell * findCell(int value);
        void constructBoardCells();
};

#endif /* defined(__tic_tac_toe_cpp__ThreeByThreeBoard__) */
