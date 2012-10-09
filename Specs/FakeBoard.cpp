#include "FakeBoard.h"

FakeBoard::FakeBoard()
{
    InitializedTimesCalled = 0;
    ApplyTimesCalled = 0;
}

FakeBoard::~FakeBoard() {}

void FakeBoard::Initialize()
{
    InitializedTimesCalled += 1;
}

void FakeBoard::Apply(int input, string owner)
{
    ApplyTimesCalled += 1;
}

vector<Cell> FakeBoard::Cells()
{
    return vector<Cell>(0);
}

Cell FakeBoard::FindCell(int value)
{
    Cell cell;
    return cell;
}