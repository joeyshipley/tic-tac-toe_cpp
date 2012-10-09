#include "ThreeByThreeBoard.h"
#include <vector>

ThreeByThreeBoard::~ThreeByThreeBoard() {}

void ThreeByThreeBoard::Initialize()
{
    cells = vector<Cell>(9);
    for(int i = 0; i < cells.size(); i++)
        cells[i].Value = i + 1;
}

void ThreeByThreeBoard::Apply(int input, string owner)
{
    Cell * cell = findCell(input);
    cell->Owner = owner;
}

vector<Cell> ThreeByThreeBoard::Cells()
{
    return cells;
}

Cell ThreeByThreeBoard::FindCell(int value)
{
    return * findCell(value);
}

Cell * ThreeByThreeBoard::findCell(int value)
{
    for(int i = 0; i < cells.size(); i++)
        if(cells[i].Value == value)
            return &cells[i];
            
    throw exception();
}