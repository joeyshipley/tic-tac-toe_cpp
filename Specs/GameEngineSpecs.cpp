#include <igloo/igloo.h>
using namespace igloo;

#include "GameEngine.h"
#include "Board.h"
#include "FakeBoard.h"
#include "Game.h"

Context(WhenStartingUpAGame)
{
    Spec(ItSetsUpANewBoard)
    {
        FakeBoard * fakeBoard = new FakeBoard();
        GameEngine * engine = new GameEngine(fakeBoard);

        engine->Start();
        Assert::That(fakeBoard->InitializedTimesCalled, Is().EqualTo(true));
        
        delete fakeBoard;
        delete engine;
    }
};

Context(WhenPerformingATurn)
{
    Spec(ItReturnsTheGamesData)
    {
        FakeBoard * fakeBoard = new FakeBoard();
        GameEngine * engine = new GameEngine(fakeBoard);

        Game game = engine->PerformTurn(1);
        Assert::That(game.Message, Is().EqualTo(""));
        
        delete fakeBoard;
        delete engine;
    }
    
    Spec(ItSendsTheInputChoiceToTheBaord)
    {
        FakeBoard * fakeBoard = new FakeBoard();
        GameEngine * engine = new GameEngine(fakeBoard);

        engine->PerformTurn(1);
        Assert::That(fakeBoard->ApplyTimesCalled, Is().EqualTo(1));
                
        delete fakeBoard;
        delete engine;
    }
};
