//
//  GameStatusAlgorithm.h
//  tic-tac-toe_cpp
//
//  Created by Joey Shipley on 10/10/12.
//  Copyright (c) 2012 Joey Shipley. All rights reserved.
//

#ifndef __tic_tac_toe_cpp__GameStatusAlgorithm__
#define __tic_tac_toe_cpp__GameStatusAlgorithm__

#include <iostream>
#include "Board.h"

class GameStatusAlgorithm
{
    public:
        virtual ~GameStatusAlgorithm() {}
        virtual string Check(Board * board) = 0;
};

#endif /* defined(__tic_tac_toe_cpp__GameStatusAlgorithm__) */
