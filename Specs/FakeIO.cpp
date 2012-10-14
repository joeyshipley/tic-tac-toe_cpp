#include "FakeIO.h"
#include "Rules.h"

FakeIO::FakeIO()
{
    OutputTimesCalled = 0;
    InputTimesCalled = 0;
    returnForInput = Rules::INVALID_INPUT_VALUE;
    outputMessages = vector<string>();
}

void FakeIO::Output(string message)
{
    outputMessages.push_back(message);
    OutputTimesCalled += 1;
}

int FakeIO::Input()
{
    InputTimesCalled += 1;
    return returnForInput;
}

void FakeIO::AndReturnsForInput(int value)
{
    returnForInput = value;
}