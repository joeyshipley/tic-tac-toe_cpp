#include "DTO.h"

Coord * DTO::BuildCoord(int x, int y)
{
    Coord * coord = new Coord();
    coord->X = x;
    coord->Y = y;
    return coord;
}

Move * DTO::BuildMove(Cell cell)
{
    Move * move = new Move();
    move->Location = cell.Value;
    move->Owner = cell.Owner;
    return move;
}