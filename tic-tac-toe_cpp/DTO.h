#ifndef __tic_tac_toe_cpp__Structs__
#define __tic_tac_toe_cpp__Structs__

#include <iostream>
#include <vector>
#include "Rules.h"
#include "Cell.h"

using namespace std;

struct Coord
{
    int X;
    int Y;
};

struct Move
{
    int Location;
    string Owner;
};

struct Game
{
    string Message;
    string Winner;
    vector<Move> Moves;
};

class DTO
{
    public:
        static Coord * BuildCoord(int x, int y);
        static Move * BuildMove(Cell cell);
        static Game * BuildGame(vector<Cell> cells, string message);
        static Game * BuildGame(vector<Cell> cells, string message, string winner);

    private:
        static void populateMoves(Game * game, vector<Cell> cells);
};

#endif /* defined(__tic_tac_toe_cpp__Structs__) */