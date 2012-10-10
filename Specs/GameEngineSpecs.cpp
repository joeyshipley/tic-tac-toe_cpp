#include <igloo/igloo.h>
using namespace igloo;

#include "GameEngine.h"
#include "Board.h"
#include "FakeBoard.h"
#include "FakeInputValidator.h"
#include "Game.h"

Context(WhenStartingUpAGame)
{
    Spec(ItSetsUpANewBoard)
    {
        FakeBoard * fakeBoard = new FakeBoard();
        FakeInputValidator * fakeValidator = new FakeInputValidator();
        fakeValidator->AndReturnsForCheck(Rules::VALID);
        GameEngine * engine = new GameEngine(fakeBoard, fakeValidator);

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
        FakeInputValidator * fakeValidator = new FakeInputValidator();
        fakeValidator->AndReturnsForCheck(Rules::VALID);
        GameEngine * engine = new GameEngine(fakeBoard, fakeValidator);

        Game game = engine->PerformTurn(1);
        Assert::That(game.Message, Is().EqualTo(""));
        
        delete fakeBoard;
        delete engine;
    }
    
    Spec(ItChecksTheInputValidity)
    {
        FakeBoard * fakeBoard = new FakeBoard();
        FakeInputValidator * fakeValidator = new FakeInputValidator();
        fakeValidator->AndReturnsForCheck(Rules::VALID);
        GameEngine * engine = new GameEngine(fakeBoard, fakeValidator);

        engine->PerformTurn(1);
        Assert::That(fakeValidator->CheckTimesCalled, Is().EqualTo(1));
                
        delete fakeBoard;
        delete engine;
    }

    Spec(ItSendsTheInputChoiceToTheBaordWhenThenInputIsValid)
    {
        FakeBoard * fakeBoard = new FakeBoard();
        FakeInputValidator * fakeValidator = new FakeInputValidator();
        fakeValidator->AndReturnsForCheck(Rules::VALID);
        GameEngine * engine = new GameEngine(fakeBoard, fakeValidator);

        engine->PerformTurn(1);
        Assert::That(fakeBoard->ApplyTimesCalled, Is().EqualTo(1));
                
        delete fakeBoard;
        delete engine;
    }

    Spec(ItDoesNotSendTheInputChoiceToTheBaordWhenThenInputIsNotValid)
    {
        FakeBoard * fakeBoard = new FakeBoard();
        FakeInputValidator * fakeValidator = new FakeInputValidator();
        fakeValidator->AndReturnsForCheck(Rules::INVALID);
        GameEngine * engine = new GameEngine(fakeBoard, fakeValidator);

        engine->PerformTurn(1);
        Assert::That(fakeBoard->ApplyTimesCalled, Is().EqualTo(0));
                
        delete fakeBoard;
        delete engine;
    }
};
