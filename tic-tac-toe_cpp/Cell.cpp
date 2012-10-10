#include "Cell.h"

Cell::Cell()
{
    this->IsValid = true;
    this->Owner = "none";
}

Cell * Cell::InvalidCell()
{
    Cell * cell = new Cell();
    cell->IsValid = false;
    return cell;
}