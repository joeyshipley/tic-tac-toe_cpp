#ifndef __tic_tac_toe_cpp__GameEngine__
#define __tic_tac_toe_cpp__GameEngine__

#include <iostream>
#include "Board.h"

class GameEngine
{
    private:
        Board * board;
        
    public:
        GameEngine(Board * board);
        void Start();
};

#endif /* defined(__tic_tac_toe_cpp__GameEngine__) */
