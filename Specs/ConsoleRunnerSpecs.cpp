#include <igloo/igloo.h>
using namespace igloo;

#include "DTO.h"
#include "ConsoleRunner.h"
#include "FakeIO.h"
#include "FakeGameEngine.h"
#include "Rules.h"
#include "Board.h"
#include "ThreeByThreeBoard.h"

using namespace std;

Context(WhenPlayingTheGameInTheConsole)
{
    FakeIO * io;
    FakeGameEngine * engine;
    ConsoleRunner * runner;
    Board * board;
    
    void SetUp()
    {
        io = new FakeIO();
        engine = new FakeGameEngine();
        runner = new ConsoleRunner(io, engine);
        board = new ThreeByThreeBoard();
        board->Initialize();

        board->Apply(1, Rules::PLAYER);
        Game * game = DTO::BuildGame(board->Cells(), Rules::NONE);
        engine->AndReturnsForPerformTurn(game);
        engine->AndReturnsForCurrentState(game);

        engine->AndReturnsForIsGameOver(false);
        engine->AndReturnsForIsGameOver(true);
    }
    
    void TearDown()
    {
        delete io;
        delete engine;
        delete runner;
        delete board;
    }
    
    Spec(ItStartsTheGameEngineUp)
    {
        runner->Go();
        Assert::That(engine->StartTimesCalled, Is().EqualTo(1));
    }
    
    Spec(ItAsksForThePlayersInput)
    {
        runner->Go();
        Assert::That(io->InputTimesCalled, Is().EqualTo(1));
    }
    
    Spec(ItPerformsAGameEngineTurn)
    {
        runner->Go();
        Assert::That(engine->PerformTurnTimesCalled, Is().EqualTo(1));
    }
    
    Spec(ItSendsTheResponseFromTheGameEngineToTheOutput)
    {
        runner->Go();
        Assert::That(io->OutputTimesCalled, Is().GreaterThan(0));
    }
};

Context(WhenRunningTheGameEngineInTheLoop)
{
    FakeIO * io;
    FakeGameEngine * engine;
    ConsoleRunner * runner;
    Board * board;
    
    void SetUp()
    {
        io = new FakeIO();
        engine = new FakeGameEngine();
        runner = new ConsoleRunner(io, engine);
        board = new ThreeByThreeBoard();
        board->Initialize();

        board->Apply(1, Rules::PLAYER);
        Game * game = DTO::BuildGame(board->Cells(), Rules::NONE);
        engine->AndReturnsForPerformTurn(game);
        engine->AndReturnsForCurrentState(game);
    }
    
    void TearDown()
    {
        delete io;
        delete engine;
        delete runner;
        delete board;
    }
    
    Spec(ItLoopsTheGameUntilItsOver)
    {
        engine->AndReturnsForIsGameOver(false);
        engine->AndReturnsForIsGameOver(false);
        engine->AndReturnsForIsGameOver(true);
        
        runner->Go();
        Assert::That(io->InputTimesCalled, Is().EqualTo(2));
    }
};

Context(WhenTheConsoleRunnerPerformsItsLoop)
{
    FakeIO * io;
    FakeGameEngine * engine;
    ConsoleRunner * runner;
    Board * board;
    
    void SetUp()
    {
        io = new FakeIO();
        engine = new FakeGameEngine();
        runner = new ConsoleRunner(io, engine);
        board = new ThreeByThreeBoard();
        board->Initialize();

        board->Apply(1, Rules::PLAYER);
        Game * game = DTO::BuildGame(board->Cells(), Rules::VALID, Rules::COMPUTER);
        engine->AndReturnsForPerformTurn(game);
        engine->AndReturnsForCurrentState(game);

        engine->AndReturnsForIsGameOver(false);
        engine->AndReturnsForIsGameOver(true);
    }
    
    void TearDown()
    {
        delete io;
        delete engine;
        delete runner;
        delete board;
    }
    
    Spec(ItFirstOutputsTheBoard)
    {
        runner->Go();
        string message = io->outputMessages[0];
        bool hasMessage = (message.find("X") != -1)
            && (message.find("2") != -1)
            && (message.find("3") != -1);
        Assert::That(hasMessage, Is().True());
    }
    
    Spec(ItSecondAsksForThePlayersMove)
    {
        runner->Go();
        string message = io->outputMessages[1];
        Assert::That(message.find("provide a move"), Is().Not().EqualTo(-1));
    }

    Spec(ItThirdInformsUsThatTheComputerIsThinking)
    {
        runner->Go();
        string message = io->outputMessages[2];
        Assert::That(message.find("computer is thinking"), Is().Not().EqualTo(-1));
    }

    Spec(ItFourthOutputsTheUpdatedBoard)
    {
        runner->Go();
        string message = io->outputMessages[3];
        bool hasMessage = (message.find("X") != -1)
            && (message.find("2") != -1)
            && (message.find("3") != -1);
        Assert::That(hasMessage, Is().True());
    }
    
    Spec(ItFifthDisplaysTheValidationMessage)
    {
        runner->Go();
        string message = io->outputMessages[4];
        Assert::That(message.find("great move"), Is().Not().EqualTo(-1));
    }

    Spec(ItAtTheLastCallOutputsTheGameOverMessage)
    {
        runner->Go();
        string message = io->outputMessages[5];
        Assert::That(message.find("You lost"), Is().Not().EqualTo(-1));
    }
};