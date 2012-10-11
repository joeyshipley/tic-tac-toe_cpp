//
//  Structs.h
//  tic-tac-toe_cpp
//
//  Created by Joey Shipley on 10/11/12.
//  Copyright (c) 2012 Joey Shipley. All rights reserved.
//

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
};

#endif /* defined(__tic_tac_toe_cpp__Structs__) */