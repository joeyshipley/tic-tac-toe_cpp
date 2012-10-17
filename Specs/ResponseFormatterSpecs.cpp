#include <igloo/igloo.h>
using namespace igloo;

#include "ResponseFormatter.h"
#include "DTO.h"
#include "Board.h"
#include "ThreeByThreeBoard.h"
#include "Rules.h"

Context(WhenFormattingTheResponse)
{
    ResponseFormatter * formatter;
    
    void SetUp()
    {
        formatter = new ResponseFormatter();
    }
    
    void TearDown()
    {
        delete formatter;
    }
    
    Spec(ItProviesFullMessagesForInvalidInput)
    {
        string message = formatter->FormatValidation(Rules::INVALID);
        Assert::That(message.find("1 to 9"), Is().Not().EqualTo(-1));
    }

    Spec(ItProviesFullMessagesForAlreadyTakenInput)
    {
        string message = formatter->FormatValidation(Rules::TAKEN);
        Assert::That(message.find("taken"), Is().Not().EqualTo(-1));
    }
    
    Spec(ItHasAFeelGoodMessageForValidInput)
    {
        string message = formatter->FormatValidation(Rules::VALID);
        Assert::That(message.find("great"), Is().Not().EqualTo(-1));
    }
    
    Spec(ItHasAComputersDoingItsThingMessage)
    {
        string message = formatter->Thinking();
        Assert::That(message.find("thinking"), Is().Not().EqualTo(-1));
    }
    
    Spec(ItHasAnAskForInputMessage)
    {
        string message = formatter->AskForInput();
        Assert::That(message.find("provide"), Is().Not().EqualTo(-1));
    }
    
    Spec(ItDisplaysTheYouWinnerMessageIfYouWinTheGame)
    {
        string message = formatter->GameOver(Rules::PLAYER_WON);
        Assert::That(message.find("won"), Is().Not().EqualTo(-1));
    }
    
    Spec(ItDisplaysTheYouLooseMessageIfYouLost)
    {
        string message = formatter->GameOver(Rules::COMPUTER_WON);
        Assert::That(message.find("lost"), Is().Not().EqualTo(-1));
    }
    
    Spec(ItDisplaysGameTiedMessageIfNoOneWon)
    {
        string message = formatter->GameOver(Rules::TIE);
        Assert::That(message.find("tie"), Is().Not().EqualTo(-1));
    }
};

    
Context(WhenFormattingTheGameBoard)
{
    ResponseFormatter * formatter;
    Board * board;
    
    void SetUp()
    {
        formatter = new ResponseFormatter();
        board = new ThreeByThreeBoard();
        board->Initialize();
    }
    
    void TearDown()
    {
        delete board;
        delete formatter;
    }
    
    Spec(ItCanDisplayTheBoard)
    {
        Game * game = DTO::BuildGame(board->Cells(), Rules::VALID);
        string formattedBoard = formatter->DisplayTicTacToe(game);
        
        Assert::That(formattedBoard.find("1"), Is().Not().EqualTo(-1));
        Assert::That(formattedBoard.find("2"), Is().Not().EqualTo(-1));
        Assert::That(formattedBoard.find("3"), Is().Not().EqualTo(-1));
        Assert::That(formattedBoard.find("4"), Is().Not().EqualTo(-1));
        Assert::That(formattedBoard.find("5"), Is().Not().EqualTo(-1));
        Assert::That(formattedBoard.find("6"), Is().Not().EqualTo(-1));
        Assert::That(formattedBoard.find("7"), Is().Not().EqualTo(-1));
        Assert::That(formattedBoard.find("8"), Is().Not().EqualTo(-1));
        Assert::That(formattedBoard.find("9"), Is().Not().EqualTo(-1));
    }
    
    Spec(ItKnowsHowToDisplayPlayerMoves)
    {
        board->Apply(5, Rules::PLAYER);
        Game * game = DTO::BuildGame(board->Cells(), Rules::VALID);
        string formattedBoard = formatter->DisplayTicTacToe(game);

        Assert::That(formattedBoard.find("X"), Is().Not().EqualTo(-1));
        Assert::That(formattedBoard.find("5"), Is().EqualTo(-1));
    }
    
    Spec(ItKnowsHowTODisplayComputerMoves)
    {
        board->Apply(3, Rules::COMPUTER);
        Game * game = DTO::BuildGame(board->Cells(), Rules::VALID);
        string formattedBoard = formatter->DisplayTicTacToe(game);

        Assert::That(formattedBoard.find("O"), Is().Not().EqualTo(-1));
        Assert::That(formattedBoard.find("3"), Is().EqualTo(-1));
    }
};