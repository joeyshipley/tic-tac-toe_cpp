#include "FakeBoard.h"

FakeBoard::FakeBoard()
{
    InitializedTimesCalled = 0;
    ApplyTimesCalled = 0;
    returnsFromFindCellCall = * Cell::InvalidCell();
}

FakeBoard::~FakeBoard() {}

void FakeBoard::Initialize()
{
    InitializedTimesCalled += 1;
}

void FakeBoard::Initialize(vector<Cell> cells) {}

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
    return returnsFromFindCellCall;
}

Cell FakeBoard::FindCellByCoordinates(int x, int y)
{
    return returnsFromFindCellCall;
}

bool FakeBoard::HasAvailableMoves()
{
    return false;
}

vector<Cell> FakeBoard::AvailableMoves()
{
    return vector<Cell>(0);
}

Board * FakeBoard::Clone()
{
    return NULL;
}

void FakeBoard::AndReturnsFromFindCell(Cell cell)
{
    returnsFromFindCellCall = cell;
}