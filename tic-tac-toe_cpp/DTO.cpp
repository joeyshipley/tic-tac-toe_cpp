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

Game * DTO::BuildGame(vector<Cell> cells, string message)
{
    return DTO::BuildGame(cells, message, Rules::NONE);
}

Game * DTO::BuildGame(vector<Cell> cells, string message, string winner)
{
    Game * game = new Game();
    game->Message = message;
    game->Winner = winner;
    game->Moves = vector<Move>(cells.size());
    for(int i = 0; i < cells.size(); i++)
        game->Moves[i] = * DTO::BuildMove(cells[i]);
    return game;
}