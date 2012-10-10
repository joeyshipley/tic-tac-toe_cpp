#include "Cell.h"

Cell::Cell()
{
    this->IsValid = true;
    this->Owner = "none";
}

Cell * Cell::Build(int value, int x, int y)
{
    Cell * cell = new Cell();
    cell->Value = value;
    cell->X = x;
    cell->Y = y;
    return cell;
}

Cell * Cell::InvalidCell()
{
    Cell * cell = new Cell();
    cell->IsValid = false;
    return cell;
}