//
//  Rules.h
//  tic-tac-toe_cpp
//
//  Created by Joey Shipley on 10/9/12.
//  Copyright (c) 2012 Joey Shipley. All rights reserved.
//

#ifndef __tic_tac_toe_cpp__Rules__
#define __tic_tac_toe_cpp__Rules__

#include <iostream>
using namespace std;

class Rules
{
    public:
        static const string NONE;
        static const string PLAYER;
        static const string COMPUTER;
    
    public:
        static const string VALID;
        static const string INVALID;
        static const string TAKEN;
};

#endif /* defined(__tic_tac_toe_cpp__Rules__) */
