//
//  FakeGameStatusChecker.h
//  tic-tac-toe_cpp
//
//  Created by Joey Shipley on 10/10/12.
//  Copyright (c) 2012 Joey Shipley. All rights reserved.
//

#ifndef __tic_tac_toe_cpp__FakeGameStatusChecker__
#define __tic_tac_toe_cpp__FakeGameStatusChecker__

#include <iostream>
#include "GameStatusAlgorithm.h"
#include "Rules.h"

class FakeGameStatusChecker : public GameStatusAlgorithm
{
    public:
        virtual string Check(Board * board);

    public:
        FakeGameStatusChecker();
        int CheckTimesCalled;
        void AndReturnsForCheck(string value);

    private:
        string returnForCheck;
};

#endif /* defined(__tic_tac_toe_cpp__FakeGameStatusChecker__) */
