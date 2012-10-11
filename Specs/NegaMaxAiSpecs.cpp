#include <igloo/igloo.h>
using namespace igloo;

#include "Board.h"
#include "ThreeByThreeBoard.h"
#include "GameStatusChecker.h"
#include "NegaMaxAi.h"
#include "Rules.h"

Context(WhenGettingAMoveFromTheNegaMaxAi)
{
    NegaMaxAi * ai;
    Board * board;
    
    void SetUp()
    {
        ai = new NegaMaxAi(new GameStatusChecker());
        board = new ThreeByThreeBoard();
        board->Initialize();
    }
    
    void TearDown()
    {
        delete board;
    }
    
    Spec(ItWinsWhenItCan)
    {
        board->Apply(9, Rules::PLAYER);
        board->Apply(5, Rules::COMPUTER);
        board->Apply(6, Rules::PLAYER);
        board->Apply(3, Rules::COMPUTER);
        board->Apply(2, Rules::PLAYER);
        
        int choice = ai->Next(board);
        Assert::That(choice, Is().EqualTo(7));
    }
    
    Spec(ItBlocksWhenItMust)
    {
        board->Apply(9, Rules::PLAYER);
        board->Apply(5, Rules::COMPUTER);
        board->Apply(8, Rules::PLAYER);
        
        int choice = ai->Next(board);
        Assert::That(choice, Is().EqualTo(7));
    }
    
    Spec(ItDoesNotTakeACornerWhenThePlayerIsSettingsUpCornerDoubleWinScenerio)
    {
        board->Apply(3, Rules::PLAYER);
        board->Apply(5, Rules::COMPUTER);
        board->Apply(7, Rules::PLAYER);
        
        int choice = ai->Next(board);
        bool choseAnEdge = (choice == 2 || choice == 4 || choice == 6 || choice == 8);
        Assert::That(choseAnEdge, Is().True());
    }
    
    Spec(ItDoesNotFallIntoTheTrapWhenThePlayerIsBeingSneakySneaky)
    {
        board->Apply(6, Rules::PLAYER);
        board->Apply(5, Rules::COMPUTER);
        board->Apply(8, Rules::PLAYER);
        
        int choice = ai->Next(board);
        bool madeBadMove = (choice == 1 || choice == 2 || choice == 7);
        Assert::That(madeBadMove, Is().False());
    }
};