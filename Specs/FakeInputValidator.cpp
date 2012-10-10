#include "FakeInputValidator.h"

FakeInputValidator::FakeInputValidator()
{
    CheckTimesCalled = 0;
}

string FakeInputValidator::Check(int input, Board * board)
{
    CheckTimesCalled += 1;
    return returnForCheck;
}

void FakeInputValidator::AndReturnsForCheck(string value)
{
    returnForCheck = value;
}