#include "FakeAi.h"

FakeAi::FakeAi()
{
    NextTimesCalled = 0;
    returnForNext = -1;
}

int FakeAi::Next(Board * board)
{
    NextTimesCalled += 1;
    return 1;
};

void FakeAi::AndReturnsForNext(int value)
{
    returnForNext = value;
}