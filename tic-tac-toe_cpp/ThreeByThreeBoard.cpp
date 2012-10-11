#include "ThreeByThreeBoard.h"

ThreeByThreeBoard::~ThreeByThreeBoard() {}

void ThreeByThreeBoard::Initialize()
{
    constructBoardCells();
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


Cell ThreeByThreeBoard::FindCellByCoordinates(int x, int y)
{
    for(int i = 0; i < cells.size(); i++)
        if(cells[i].X == x && cells[i].Y == y)
            return cells[i];
    
    return * Cell::InvalidCell();
}

bool ThreeByThreeBoard::HasAvailableMoves()
{
    for(int i = 0; i < cells.size(); i++)
        if(cells[i].Owner == Rules::NONE)
            return true;
            
    return false;
}

Cell * ThreeByThreeBoard::findCell(int value)
{
    for(int i = 0; i < cells.size(); i++)
        if(cells[i].Value == value)
            return &cells[i];

    return Cell::InvalidCell();
}

void ThreeByThreeBoard::constructBoardCells()
{
    cells = vector<Cell>(9);
    cells[0] = * Cell::Build(1, -1, -1);
    cells[1] = * Cell::Build(2, -1,  0);
    cells[2] = * Cell::Build(3, -1,  1);
    cells[3] = * Cell::Build(4,  0, -1);
    cells[4] = * Cell::Build(5,  0,  0);
    cells[5] = * Cell::Build(6,  0,  1);
    cells[6] = * Cell::Build(7,  1, -1);
    cells[7] = * Cell::Build(8,  1,  0);
    cells[8] = * Cell::Build(9,  1,  1);
}