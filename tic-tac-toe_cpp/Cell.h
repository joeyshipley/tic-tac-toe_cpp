#ifndef __tic_tac_toe_cpp__Cell__
#define __tic_tac_toe_cpp__Cell__

#include <iostream>
using namespace std;

class Cell
{
    public:
        int Value;
        string Owner;
        int X;
        int Y;
        bool IsValid;

    public:
        Cell();
        static Cell * Build(int value, int x, int y);
        static Cell * InvalidCell();
};

#endif /* defined(__tic_tac_toe_cpp__Cell__) */
