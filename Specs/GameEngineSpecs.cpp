#include <igloo/igloo.h>
using namespace igloo;

#include "GameEngine.h"
#include "Board.h"
#include "FakeBoard.h"
#include "FakeInputValidator.h"
#include "FakeGameStatusChecker.h"
#include "FakeAi.h"

Context(WhenStartingUpAGame)
{
    FakeBoard * board;
    FakeInputValidator * validator;
    FakeGameStatusChecker * status;
    FakeAi * ai;
    GameEngine * engine;
    
    void SetUp()
    {
        board = new FakeBoard();
        validator = new FakeInputValidator();
        status = new FakeGameStatusChecker();
        ai = new FakeAi();
        engine = new GameEngine(board, validator, status, ai);
    }
    
    void TearDown()
    {
        delete board;
        delete validator;
        delete status;
        delete ai;
        delete engine;
    }
    
    Spec(ItSetsUpANewBoard)
    {
        validator->AndReturnsForCheck(Rules::VALID);

        engine->Start();
        Assert::That(board->InitializedTimesCalled, Is().EqualTo(true));
    }
};

Context(WhenPerformingATurn)
{
    FakeBoard * board;
    FakeInputValidator * validator;
    FakeGameStatusChecker * status;
    FakeAi * ai;
    GameEngine * engine;
    
    void SetUp()
    {
        board = new FakeBoard();
        validator = new FakeInputValidator();
        status = new FakeGameStatusChecker();
        ai = new FakeAi();
        engine = new GameEngine(board, validator, status, ai);
    }
    
    void TearDown()
    {
        delete board;
        delete validator;
        delete status;
        delete ai;
        delete engine;
    }
    
    Spec(ItReturnsTheGamesData)
    {
        validator->AndReturnsForCheck(Rules::VALID);

        Game * game = engine->PerformTurn(1);
        Assert::That(game->Message, Is().EqualTo(Rules::VALID));
    }
    
    Spec(ItChecksTheInputValidity)
    {
        validator->AndReturnsForCheck(Rules::VALID);

        engine->PerformTurn(1);
        Assert::That(validator->CheckTimesCalled, Is().EqualTo(1));
    }

    Spec(ItSendsTheInputChoiceToTheBaordWhenThenInputIsValid)
    {
        validator->AndReturnsForCheck(Rules::VALID);
        status->AndReturnsForCheck(Rules::TIE);

        engine->PerformTurn(1);
        Assert::That(board->ApplyTimesCalled, Is().EqualTo(1));
    }

    Spec(ItDoesNotSendTheInputChoiceToTheBaordWhenThenInputIsNotValid)
    {
        validator->AndReturnsForCheck(Rules::INVALID);

        engine->PerformTurn(1);
        Assert::That(board->ApplyTimesCalled, Is().EqualTo(0));
    }
       
    Spec(ItChecksIfTheGameIsOver)
    {
        validator->AndReturnsForCheck(Rules::VALID);
        status->AndReturnsForCheck(Rules::TIE);

        engine->PerformTurn(1);
        Assert::That(status->CheckTimesCalled, Is().EqualTo(2));
    }
    
    Spec(ItPerformsTheComputersMoveIfTheGameWasNotWonByThePlayer)
    {
        validator->AndReturnsForCheck(Rules::VALID);
        status->AndReturnsForCheck(Rules::NONE);
        
        engine->PerformTurn(1);
        Assert::That(ai->NextTimesCalled, Is().EqualTo(1));
        Assert::That(board->ApplyTimesCalled, Is().EqualTo(2));
    }
    
        
    Spec(ItChecksToSeeIfTheComputerWonAfterItMakesItsMove)
    {
        validator->AndReturnsForCheck(Rules::VALID);
        status->AndReturnsForCheck(Rules::NONE);
        
        engine->PerformTurn(1);
        Assert::That(status->CheckTimesCalled, Is().EqualTo(2));
    }
};

Context(WhenAskingIfTheGameIsOver)
{
    FakeBoard * board;
    FakeInputValidator * validator;
    FakeGameStatusChecker * status;
    FakeAi * ai;
    GameEngine * engine;
    
    void SetUp()
    {
        board = new FakeBoard();
        validator = new FakeInputValidator();
        status = new FakeGameStatusChecker();
        ai = new FakeAi();
        engine = new GameEngine(board, validator, status, ai);
    }
    
    void TearDown()
    {
        delete board;
        delete validator;
        delete status;
        delete ai;
        delete engine;
    }
    
    Spec(ItLetsUsKnowThatItIsOverIfThePlayerHasWon)
    {
        status->AndReturnsForCheck(Rules::PLAYER);
        bool isGameOver = engine->IsGameOver();
        Assert::That(isGameOver, Is().True());
    }

    Spec(ItLetsUsKnowThatItIsOverIfTheComputerHasWon)
    {
        status->AndReturnsForCheck(Rules::COMPUTER);
        bool isGameOver = engine->IsGameOver();
        Assert::That(isGameOver, Is().True());
    }

    Spec(ItLetsUsKnowThatItIsOverIfTheGameIsATie)
    {
        status->AndReturnsForCheck(Rules::TIE);
        bool isGameOver = engine->IsGameOver();
        Assert::That(isGameOver, Is().True());
    }
    
    Spec(ItLetsUsKnowThatItIsNotOverWhenItsStillGoing)
    {
        status->AndReturnsForCheck(Rules::NONE);
        bool isGameOver = engine->IsGameOver();
        Assert::That(isGameOver, Is().False());
    }
};
