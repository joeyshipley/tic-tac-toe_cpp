#ifndef __tic_tac_toe_cpp__Rules__
#define __tic_tac_toe_cpp__Rules__

#include <iostream>
using namespace std;

class Rules
{
    public:
        static const string NONE;
        static const string PLAYER;
        static const string COMPUTER;
        
    public:
        static const string INPROGRESS;
        static const string TIE;
        static const string PLAYER_WON;
        static const string COMPUTER_WON;
    
    public:
        static const string VALID;
        static const string INVALID;
        static const string TAKEN;
        
    public:
        static const int INVALID_INPUT_VALUE;
};

#endif /* defined(__tic_tac_toe_cpp__Rules__) */
