#ifndef __tic_tac_toe_cpp__FakeIO__
#define __tic_tac_toe_cpp__FakeIO__

#include <iostream>
#include "IO.h"
#include <vector>

using namespace std;

class FakeIO : public IO
{
    public:
        virtual void Output(string message);
        virtual int Input();
        
    public:
        FakeIO();
        int OutputTimesCalled;
        int InputTimesCalled;
        void AndReturnsForInput(int value);
        vector<string> outputMessages;

    private:
        int returnForInput;
};

#endif /* defined(__tic_tac_toe_cpp__FakeIO__) */
