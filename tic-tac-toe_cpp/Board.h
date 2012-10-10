#ifndef __tic_tac_toe_cpp__Board__
#define __tic_tac_toe_cpp__Board__

#include <iostream>
#include <vector>
#include "Cell.h"

class Board
{
    public:
        virtual ~Board() {}
        virtual void Initialize() = 0;
        virtual void Apply(int input, string owner) = 0;
        virtual vector<Cell> Cells() = 0;
        virtual Cell FindCell(int value) = 0;
        virtual Cell FindCellByCoordinates(int x, int y) = 0;
        virtual bool HasAvailableMoves() = 0;
};

#endif /* defined(__tic_tac_toe_cpp__Board__) */
