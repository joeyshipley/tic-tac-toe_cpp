#ifndef __tic_tac_toe_cpp__FakeInputValidator__
#define __tic_tac_toe_cpp__FakeInputValidator__

#include <iostream>
#include "InputValidator.h"
#include "Board.h"

class FakeInputValidator : public InputValidator
{
    public:
        virtual string Check(int input, Board * board);
        
    public:
        FakeInputValidator();
        int CheckTimesCalled;
        void AndReturnsForCheck(string value);
        
    private:
        string returnForCheck;
};

#endif /* defined(__tic_tac_toe_cpp__FakeInputValidator__) */
