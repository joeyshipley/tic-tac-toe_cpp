#ifndef __tic_tac_toe_cpp__ConsoleIO__
#define __tic_tac_toe_cpp__ConsoleIO__

#include <iostream>
#include "IO.h"

class ConsoleIO : public IO
{
    public:
        virtual void Output(string message);
        virtual int Input(string value);
        
    protected:
        virtual int convertInputToInt(string input);
};

#endif /* defined(__tic_tac_toe_cpp__ConsoleIO__) */
