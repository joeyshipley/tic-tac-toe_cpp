#ifndef __tic_tac_toe_cpp__Cell__
#define __tic_tac_toe_cpp__Cell__

#include <iostream>
using namespace std;

class Cell
{
    public:
        int Value;
        string Owner;
        bool IsValid;
        Cell();
        static Cell * InvalidCell();
};

#endif /* defined(__tic_tac_toe_cpp__Cell__) */
