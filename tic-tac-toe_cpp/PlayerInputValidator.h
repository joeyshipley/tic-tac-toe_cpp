#ifndef __tic_tac_toe_cpp__PlayerInputValidator__
#define __tic_tac_toe_cpp__PlayerInputValidator__

#include <iostream>
#include "InputValidator.h"
#include "Rules.h"
#include "Board.h"
using namespace std;

class PlayerInputValidator : public InputValidator
{
    public:
        virtual string Check(int input, Board * board);
};

#endif /* defined(__tic_tac_toe_cpp__PlayerInputValidator__) */
