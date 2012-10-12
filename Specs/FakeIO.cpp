#include "FakeIO.h"
#include "Rules.h"

FakeIO::FakeIO()
{
    OutputTimesCalled = 0;
    InputTimesCalled = 0;
    returnForInput = Rules::INVALID_INPUT_VALUE;
}

void FakeIO::Output(string message)
{
    OutputTimesCalled += 1;
}

int FakeIO::Input(string value)
{
    InputTimesCalled += 1;
    return returnForInput;
}

void FakeIO::AndReturnsForInput(int value)
{
    returnForInput = value;
}