#ifndef __tic_tac_toe_cpp__Game__
#define __tic_tac_toe_cpp__Game__

#include <iostream>
#include <vector>
#include "Rules.h"
#include "Board.h"
#include "DTO.h"

using namespace std;

class Game
{
    public:
        string Message;
        string Winner;
        vector<Move> Moves;
        
    public:
        Game();
        static Game * Build(vector<Cell> cells, string message);
        static Game * Build(vector<Cell> cells, string message, string winner);

};

#endif /* defined(__tic_tac_toe_cpp__Game__) */
