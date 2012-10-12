#ifndef __tic_tac_toe_cpp__IO__
#define __tic_tac_toe_cpp__IO__

#include <iostream>

using namespace std;

class IO
{
    public:
        virtual void Output(string message) = 0;
        virtual int Input(string value) = 0;
};

#endif /* defined(__tic_tac_toe_cpp__IO__) */
