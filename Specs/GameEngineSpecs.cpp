#include <igloo/igloo.h>
using namespace igloo;

#include "GameEngine.h"
#include "Board.h"
#include "FakeBoard.h"
#include "FakeInputValidator.h"
#include "FakeGameStatusChecker.h"
#include "Game.h"

Context(WhenStartingUpAGame)
{
    Spec(ItSetsUpANewBoard)
    {
        FakeBoard * fakeBoard = new FakeBoard();
        FakeInputValidator * fakeValidator = new FakeInputValidator();
        fakeValidator->AndReturnsForCheck(Rules::VALID);
        FakeGameStatusChecker * fakeGameStatusChecker = new FakeGameStatusChecker();
        GameEngine * engine = new GameEngine(fakeBoard, fakeValidator, fakeGameStatusChecker);

        engine->Start();
        Assert::That(fakeBoard->InitializedTimesCalled, Is().EqualTo(true));
        
        delete fakeBoard;
        delete fakeValidator;
        delete fakeGameStatusChecker;
        delete engine;
    }
};

Context(WhenPerformingATurn)
{
    FakeBoard * fakeBoard;
    FakeInputValidator * fakeValidator;
    FakeGameStatusChecker * fakeGameStatusChecker;
    GameEngine * engine;
    
    void SetUp()
    {
        fakeBoard = new FakeBoard();
        fakeValidator = new FakeInputValidator();
        fakeGameStatusChecker = new FakeGameStatusChecker();
        engine = new GameEngine(fakeBoard, fakeValidator, fakeGameStatusChecker);
    }
    
    void TearDown()
    {
        delete fakeBoard;
        delete fakeValidator;
        delete fakeGameStatusChecker;
        delete engine;
    }
    
    Spec(ItReturnsTheGamesData)
    {
        fakeValidator->AndReturnsForCheck(Rules::VALID);

        Game game = engine->PerformTurn(1);
        Assert::That(game.Message, Is().EqualTo(""));
    }
    
    Spec(ItChecksTheInputValidity)
    {
        fakeValidator->AndReturnsForCheck(Rules::VALID);

        engine->PerformTurn(1);
        Assert::That(fakeValidator->CheckTimesCalled, Is().EqualTo(1));
    }
    
    Spec(ItChecksIfTheGameIsOver)
    {
        fakeValidator->AndReturnsForCheck(Rules::VALID);

        engine->PerformTurn(1);
        Assert::That(fakeGameStatusChecker->CheckTimesCalled, Is().EqualTo(1));
    }

    Spec(ItSendsTheInputChoiceToTheBaordWhenThenInputIsValid)
    {
        fakeValidator->AndReturnsForCheck(Rules::VALID);

        engine->PerformTurn(1);
        Assert::That(fakeBoard->ApplyTimesCalled, Is().EqualTo(1));
    }

    Spec(ItDoesNotSendTheInputChoiceToTheBaordWhenThenInputIsNotValid)
    {
        fakeValidator->AndReturnsForCheck(Rules::INVALID);

        engine->PerformTurn(1);
        Assert::That(fakeBoard->ApplyTimesCalled, Is().EqualTo(0));
    }
};
