#ifndef __tic_tac_toe_cpp__ResponseFormatter__
#define __tic_tac_toe_cpp__ResponseFormatter__

#include <iostream>
#include "DTO.h"

using namespace std;

class ResponseFormatter
{
    public:
        string FormatValidation(string validation);
        string AskForInput();
        string Thinking();
        string GameOver(string winner);
        string DisplayTicTacToe(Game * game);
        
    private:
        string display(Move move);
};

#endif /* defined(__tic_tac_toe_cpp__ResponseFormatter__) */
