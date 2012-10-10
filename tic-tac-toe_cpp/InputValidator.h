#ifndef __tic_tac_toe_cpp__InputValidator__
#define __tic_tac_toe_cpp__InputValidator__

#include <iostream>
#include "Rules.h"
#include "Board.h"
using namespace std;

class InputValidator
{
    public:
        virtual string Check(int input, Board * board) = 0;
};

#endif /* defined(__tic_tac_toe_cpp__InputValidator__) */
