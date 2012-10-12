#ifndef __tic_tac_toe_cpp__FakeIO__
#define __tic_tac_toe_cpp__FakeIO__

#include <iostream>
#include "IO.h"

class FakeIO
{
    public:
        virtual void Output(string message);
        virtual int Input(string value);
        
    public:
        FakeIO();
        int OutputTimesCalled;
        int InputTimesCalled;
        void AndReturnsForInput(int value);

    private:
        int returnForInput;
};

#endif /* defined(__tic_tac_toe_cpp__FakeIO__) */
