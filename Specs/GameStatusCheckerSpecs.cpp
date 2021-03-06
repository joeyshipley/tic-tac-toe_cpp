#include <igloo/igloo.h>
using namespace igloo;

#include "GameStatusChecker.h"
#include "Board.h"
#include "ThreeByThreeBoard.h"
#include "Rules.h"

Context(WhenCheckingForAWinner)
{
    GameStatusChecker * statusChecker;
    Board * board;
    
    void SetUp()
    {
        statusChecker = new GameStatusChecker();
        board = new ThreeByThreeBoard();
        board->Initialize();
    }
    
    void TearDown()
    {
        delete board;
        delete statusChecker;
    }
    
    Spec(ItConfirmsThatNoOneHasWon)
    {
        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::INPROGRESS));
    }
    
    Spec(ItConfirmsThatTheGameIsATie)
    {
        board->Apply(1, Rules::PLAYER);
        board->Apply(9, Rules::PLAYER);
        board->Apply(3, Rules::PLAYER);
        board->Apply(4, Rules::PLAYER);
        board->Apply(8, Rules::PLAYER);

        board->Apply(5, Rules::COMPUTER);
        board->Apply(2, Rules::COMPUTER);
        board->Apply(6, Rules::COMPUTER);
        board->Apply(7, Rules::COMPUTER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::TIE));
    }
    
    Spec(ItConfirmsThePlayerCanWinFromTheTopRow)
    {
        board->Apply(1, Rules::PLAYER);
        board->Apply(2, Rules::PLAYER);
        board->Apply(3, Rules::PLAYER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::PLAYER_WON));
    }

    Spec(ItConfirmsThePlayerCanWinFromTheMiddleRow)
    {
        board->Apply(4, Rules::PLAYER);
        board->Apply(5, Rules::PLAYER);
        board->Apply(6, Rules::PLAYER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::PLAYER_WON));
    }

    Spec(ItConfirmsThePlayerCanWinFromTheBottomRow)
    {
        board->Apply(7, Rules::PLAYER);
        board->Apply(8, Rules::PLAYER);
        board->Apply(9, Rules::PLAYER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::PLAYER_WON));
    }

    Spec(ItConfirmsThePlayerCanWinFromTheLeftColumn)
    {
        board->Apply(1, Rules::PLAYER);
        board->Apply(4, Rules::PLAYER);
        board->Apply(7, Rules::PLAYER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::PLAYER_WON));
    }

    Spec(ItConfirmsThePlayerCanWinFromTheCenterColumn)
    {
        board->Apply(2, Rules::PLAYER);
        board->Apply(5, Rules::PLAYER);
        board->Apply(8, Rules::PLAYER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::PLAYER_WON));
    }

    Spec(ItConfirmsThePlayerCanWinFromTheRightColumn)
    {
        board->Apply(3, Rules::PLAYER);
        board->Apply(6, Rules::PLAYER);
        board->Apply(9, Rules::PLAYER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::PLAYER_WON));
    }

    Spec(ItConfirmsThePlayerCanWinFromTheTopLeftStartingDiagonal)
    {
        board->Apply(1, Rules::PLAYER);
        board->Apply(5, Rules::PLAYER);
        board->Apply(9, Rules::PLAYER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::PLAYER_WON));
    }

    Spec(ItConfirmsThePlayerCanWinFromTheBottomLeftStartingDiagonal)
    {
        board->Apply(7, Rules::PLAYER);
        board->Apply(5, Rules::PLAYER);
        board->Apply(3, Rules::PLAYER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::PLAYER_WON));
    }
      
    Spec(ItConfirmsTheComputerCanWinFromTheTopRow)
    {
        board->Apply(1, Rules::COMPUTER);
        board->Apply(2, Rules::COMPUTER);
        board->Apply(3, Rules::COMPUTER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::COMPUTER_WON));
    }

    Spec(ItConfirmsTheComputerCanWinFromTheMiddleRow)
    {
        board->Apply(4, Rules::COMPUTER);
        board->Apply(5, Rules::COMPUTER);
        board->Apply(6, Rules::COMPUTER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::COMPUTER_WON));
    }

    Spec(ItConfirmsTheComputerCanWinFromTheBottomRow)
    {
        board->Apply(7, Rules::COMPUTER);
        board->Apply(8, Rules::COMPUTER);
        board->Apply(9, Rules::COMPUTER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::COMPUTER_WON));
    }

    Spec(ItConfirmsTheComputerCanWinFromTheLeftColumn)
    {
        board->Apply(1, Rules::COMPUTER);
        board->Apply(4, Rules::COMPUTER);
        board->Apply(7, Rules::COMPUTER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::COMPUTER_WON));
    }

    Spec(ItConfirmsTheComputerCanWinFromTheCenterColumn)
    {
        board->Apply(2, Rules::COMPUTER);
        board->Apply(5, Rules::COMPUTER);
        board->Apply(8, Rules::COMPUTER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::COMPUTER_WON));
    }

    Spec(ItConfirmsTheComputerCanWinFromTheRightColumn)
    {
        board->Apply(3, Rules::COMPUTER);
        board->Apply(6, Rules::COMPUTER);
        board->Apply(9, Rules::COMPUTER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::COMPUTER_WON));
    }

    Spec(ItConfirmsTheComputerCanWinFromTheTopLeftStartingDiagonal)
    {
        board->Apply(1, Rules::COMPUTER);
        board->Apply(5, Rules::COMPUTER);
        board->Apply(9, Rules::COMPUTER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::COMPUTER_WON));
    }

    Spec(ItConfirmsTheComputerCanWinFromTheBottomLeftStartingDiagonal)
    {
        board->Apply(7, Rules::COMPUTER);
        board->Apply(5, Rules::COMPUTER);
        board->Apply(3, Rules::COMPUTER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::COMPUTER_WON));
    }
};

Context(WhenTheASpecificSetOfMovesHasBeenPlayedLeavingThePlayerTheWinnerItDoesNotReturnATieResponse)
{
    GameStatusChecker * statusChecker;
    Board * board;
    
    void SetUp()
    {
        statusChecker = new GameStatusChecker();
        board = new ThreeByThreeBoard();
        board->Initialize();
    }
    
    void TearDown()
    {
        delete board;
        delete statusChecker;
    }
    
    Spec(ItConfirmsThatNoOneHasWon)
    {
        board->Apply(8, Rules::PLAYER);
        board->Apply(2, Rules::COMPUTER);
        board->Apply(4, Rules::PLAYER);
        board->Apply(1, Rules::COMPUTER);
        board->Apply(3, Rules::PLAYER);
        board->Apply(5, Rules::COMPUTER);
        board->Apply(9, Rules::PLAYER);
        board->Apply(6, Rules::COMPUTER);
        board->Apply(7, Rules::PLAYER);
        
        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::PLAYER_WON));
    }
};