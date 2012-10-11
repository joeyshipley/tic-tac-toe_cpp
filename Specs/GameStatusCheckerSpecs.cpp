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
        Assert::That(winner, Is().EqualTo(Rules::NONE));
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
    
    Spec(ItConfirmsThePlayerCanWinFromARow)
    {
        board->Apply(1, Rules::PLAYER);
        board->Apply(2, Rules::PLAYER);
        board->Apply(3, Rules::PLAYER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::PLAYER));
    }

    Spec(ItConfirmsThePlayerCanWinFromAColumn)
    {
        board->Apply(1, Rules::PLAYER);
        board->Apply(4, Rules::PLAYER);
        board->Apply(7, Rules::PLAYER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::PLAYER));
    }

    Spec(ItConfirmsThePlayerCanWinFromTheTopLeftStartingDiagonal)
    {
        board->Apply(1, Rules::PLAYER);
        board->Apply(5, Rules::PLAYER);
        board->Apply(9, Rules::PLAYER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::PLAYER));
    }

    Spec(ItConfirmsThePlayerCanWinFromTheBottomLeftStartingDiagonal)
    {
        board->Apply(7, Rules::PLAYER);
        board->Apply(5, Rules::PLAYER);
        board->Apply(3, Rules::PLAYER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::PLAYER));
    }
    
    Spec(ItConfirmsTheComputerCanWinFromARow)
    {
        board->Apply(1, Rules::COMPUTER);
        board->Apply(2, Rules::COMPUTER);
        board->Apply(3, Rules::COMPUTER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::COMPUTER));
    }

    Spec(ItConfirmsTheComputerCanWinFromAColumn)
    {
        board->Apply(1, Rules::COMPUTER);
        board->Apply(4, Rules::COMPUTER);
        board->Apply(7, Rules::COMPUTER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::COMPUTER));
    }

    Spec(ItConfirmsTheComputerCanWinFromTheTopLeftStartingDiagonal)
    {
        board->Apply(1, Rules::COMPUTER);
        board->Apply(5, Rules::COMPUTER);
        board->Apply(9, Rules::COMPUTER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::COMPUTER));
    }

    Spec(ItConfirmsTheComputerCanWinFromTheBottomLeftStartingDiagonal)
    {
        board->Apply(7, Rules::COMPUTER);
        board->Apply(5, Rules::COMPUTER);
        board->Apply(3, Rules::COMPUTER);

        string winner = statusChecker->Check(board);
        Assert::That(winner, Is().EqualTo(Rules::COMPUTER));
    }
};