#include <igloo/igloo.h>
using namespace igloo;

#include "ConsoleIO.h"
#include "Rules.h"

class SpecIO : public ConsoleIO
{
    public:
        virtual int parentConvertInputToInt(string input);
};

int SpecIO::parentConvertInputToInt(string input)
{
    return this->convertInputToInt(input);
}

Context(WhenProvidingInput)
{
    SpecIO * io;
    
    void SetUp()
    {
        io = new SpecIO();
    }
    
    void TearDown()
    {
        delete io;
    }
    
    Spec(ItTurnsTheStringNumericsInputIntoAnInt)
    {
        Assert::That(io->parentConvertInputToInt("1"), Is().EqualTo(1));
    }
    
    Spec(ItTurnsNonNumericSTringsIntoInvalidInputValues)
    {
        Assert::That(io->parentConvertInputToInt("a"), Is().EqualTo(Rules::INVALID_INPUT_VALUE));
    }
};