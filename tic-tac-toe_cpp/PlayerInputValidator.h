//
//  PlayerInputValidator.h
//  tic-tac-toe_cpp
//
//  Created by Joey Shipley on 10/10/12.
//  Copyright (c) 2012 Joey Shipley. All rights reserved.
//

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
