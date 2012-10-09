#ifndef __tic_tac_toe_cpp__FakeBoard__
#define __tic_tac_toe_cpp__FakeBoard__

#include <iostream>
#include "Board.h"

class FakeBoard : public Board
{
    public:
        virtual ~FakeBoard();
        virtual void Initialize();
        virtual bool IsRealBoard();
};

#endif /* defined(__tic_tac_toe_cpp__FakeBoard__) */
