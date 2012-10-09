#ifndef __tic_tac_toe_cpp__ThreeByThreeBoard__
#define __tic_tac_toe_cpp__ThreeByThreeBoard__

#include <iostream>
#include "Board.h"

class ThreeByThreeBoard : public Board
{
    public:
        virtual ~ThreeByThreeBoard();
        virtual void Initialize();
        virtual bool IsRealBoard();
};

#endif /* defined(__tic_tac_toe_cpp__ThreeByThreeBoard__) */
