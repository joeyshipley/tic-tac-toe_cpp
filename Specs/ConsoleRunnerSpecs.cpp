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