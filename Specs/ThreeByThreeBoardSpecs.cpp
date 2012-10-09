#include <igloo/igloo.h>
using namespace igloo;

#include "Board.h"
#include "ThreeByThreeBoard.h"
#include "Rules.h"

Context(WhenThe3By3BoardIsInitialized)
{
    Spec(ItHas9Cells)
    {
        Board * board = new ThreeByThreeBoard();
        board->Initialize();
        vector<Cell> cells = board->Cells();

        Assert::That(cells.size(), Is().EqualTo(9));
    }

    Spec(ItHasAFirstCellWithAValueOf1)
    {
        Board * board = new ThreeByThreeBoard();
        board->Initialize();
        vector<Cell> cells = board->Cells();

        Assert::That(cells.front().Value, Is().EqualTo(1));
    }

    Spec(ItHasALstCellWithAValueOf9)
    {
        Board * board = new ThreeByThreeBoard();
        board->Initialize();
        vector<Cell> cells = board->Cells();

        Assert::That(cells.back().Value, Is().EqualTo(9));
    }
};

Context(WhenAskingTheBoardForASpecificCell)
{
    Spec(ItReturnsTheCorrectCell)
    {
        Board * board = new ThreeByThreeBoard();
        board->Initialize();
        Cell cell = board->FindCell(2);
        
        Assert::That(cell.Value, Is().EqualTo(2));
    }
};

Context(WhenAskingTheBoardToApplyAnInputChoice)
{
    Spec(ItAppliesTheChoice)
    {
        Board * board = new ThreeByThreeBoard();
        board->Initialize();
        board->Apply(1, Rules::PLAYER);
        Cell cell = board->FindCell(1);

        Assert::That(cell.Owner, Is().EqualTo(Rules::PLAYER));
    }
};