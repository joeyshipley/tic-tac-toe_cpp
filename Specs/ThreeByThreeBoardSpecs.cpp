#include <igloo/igloo.h>
using namespace igloo;

#include "Board.h"
#include "ThreeByThreeBoard.h"
#include "Rules.h"

Context(WhenThe3By3BoardIsInitialized)
{
    Board * board;
    
    void SetUp()
    {
        board = new ThreeByThreeBoard();
        board->Initialize();
    }
    
    void TearDown()
    {
        delete board;
    }
    
    Spec(ItHas9Cells)
    {
        vector<Cell> cells = board->Cells();
        Assert::That(cells.size(), Is().EqualTo(9));
    }

    Spec(ItHasAFirstCellWithAValueOf1)
    {
        vector<Cell> cells = board->Cells();
        Assert::That(cells.front().Value, Is().EqualTo(1));
    }

    Spec(ItHasALstCellWithAValueOf9)
    {
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

Context(WhenAskingTheBoardIfItHasAvailableMoves)
{
    Board * board;
    
    void SetUp()
    {
        board = new ThreeByThreeBoard();
        board->Initialize();
    }
    
    void TearDown()
    {
        delete board;
    }
    
    Spec(ItLetsUsKnowWhenItDoesnt)
    {
        for(int i = 0; i < board->Cells().size(); i++)
            board->Apply(i + 1, Rules::PLAYER);
            
        bool hasAvailableMoves = board->HasAvailableMoves();
        Assert::That(hasAvailableMoves, Is().EqualTo(false));
    }
    
    Spec(ItLetsUsKnowWhenItDoes)
    {
        bool hasAvailableMoves = board->HasAvailableMoves();
        Assert::That(hasAvailableMoves, Is().EqualTo(true));
    }
};