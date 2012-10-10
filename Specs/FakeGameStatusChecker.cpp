//
//  FakeGameStatusChecker.cpp
//  tic-tac-toe_cpp
//
//  Created by Joey Shipley on 10/10/12.
//  Copyright (c) 2012 Joey Shipley. All rights reserved.
//

#include "FakeGameStatusChecker.h"

FakeGameStatusChecker::FakeGameStatusChecker()
{
    CheckTimesCalled = 0;
    returnForCheck = Rules::NONE;
}

string FakeGameStatusChecker::Check(Board * board)
{
    CheckTimesCalled += 1;
    return returnForCheck;
}

void FakeGameStatusChecker::AndReturnsForCheck(string value)
{
    returnForCheck = value;
}