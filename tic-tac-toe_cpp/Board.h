#ifndef __tic_tac_toe_cpp__Board__
#define __tic_tac_toe_cpp__Board__

#include <iostream>

class Board
{
    public:
        virtual ~Board() {}
        virtual void Initialize() = 0;
        virtual bool IsRealBoard() = 0;
};

#endif /* defined(__tic_tac_toe_cpp__Board__) */
