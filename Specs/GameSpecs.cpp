#include <igloo/igloo.h>
using namespace igloo;

#include "DTO.h"
#include "Board.h"
#include "ThreeByThreeBoard.h"
#include "Rules.h"

Context(WhenBuildingTheGameResponseData)
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
    
    Spec(ItSetsTheMessage)
    {
        Game * game = DTO::BuildGame(board->Cells(), Rules::INVALID, Rules::NONE);
        Assert::That(game->Message, Is().EqualTo(Rules::INVALID));
    }
    
    Spec(ItSetsTheCurrentWinner)
    {
        Game * game = DTO::BuildGame(board->Cells(), Rules::INVALID, Rules::NONE);
        Assert::That(game->Winner, Is().EqualTo(Rules::NONE));
    }
    
    Spec(ItPopulatesThePlayersMoves)
    {
        board->Apply(1, Rules::PLAYER);
        
        Game * game = DTO::BuildGame(board->Cells(), Rules::INVALID, Rules::NONE);
        Assert::That(game->Moves[0].Location, Is().EqualTo(1));
        Assert::That(game->Moves[0].Owner, Is().EqualTo(Rules::PLAYER));
    }

    Spec(ItPopulatesTheComputersMoves)
    {
        board->Apply(1, Rules::COMPUTER);
        
        Game * game = DTO::BuildGame(board->Cells(), Rules::INVALID, Rules::NONE);
        Assert::That(game->Moves[0].Location, Is().EqualTo(1));
        Assert::That(game->Moves[0].Owner, Is().EqualTo(Rules::COMPUTER));
    }
};