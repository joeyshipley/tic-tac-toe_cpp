#include <igloo/igloo.h>
using namespace igloo;

#include "PlayerInputValidator.h"
#include "FakeBoard.h"
#include "Board.h"
#include "Rules.h"

Context(WhenValidatingAMoveThatIsNotValid)
{
    Spec(ItLetsUsKnowTheInputIsNotValid)
    {
        FakeBoard * board = new FakeBoard();
    
        PlayerInputValidator validator;
        string response = validator.Check(-99, board);
        Assert::That(response, Is().EqualTo(Rules::INVALID));
    }
};

Context(WhenValidatingAMoveThatHasBeenTaken)
{
    Spec(ItLetsUsKnowTheInputHasAlreadyBeenTaken)
    {
        FakeBoard * board = new FakeBoard();
        Cell cell;
        cell.Value = 1;
        cell.Owner = Rules::COMPUTER;
        board->AndReturnsFromFindCell(cell);
        
        PlayerInputValidator validator;
        string response = validator.Check(1, board);
        Assert::That(response, Is().EqualTo(Rules::TAKEN));
    }
};

Context(WhenValidatingAMoveThatIsValidAndNotTaken)
{
    Spec(ItLetsUsKnowAllIsWell)
    {
        FakeBoard * board = new FakeBoard();
        Cell cell;
        cell.Value = 1;
        cell.Owner = Rules::NONE;
        board->AndReturnsFromFindCell(cell);
        
        PlayerInputValidator validator;
        string response = validator.Check(1, board);
        Assert::That(response, Is().EqualTo(Rules::VALID));
    }
};