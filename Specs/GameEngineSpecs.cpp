#include <igloo/igloo.h>
using namespace igloo;

#include "GameEngine.h"
#include "Board.h"
#include "FakeBoard.h"

Context(WhenStartingUpAGame)
{
    Spec(ItSetupsUpANewBoard)
    {
        Board * fakeBoard = new FakeBoard();
        GameEngine * engine = new GameEngine(fakeBoard);
        engine->Start();
        
        Assert::That(fakeBoard->IsRealBoard(), Is().EqualTo(false));
    }
};
