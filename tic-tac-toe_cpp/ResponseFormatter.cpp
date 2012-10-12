#include "ResponseFormatter.h"
#include <sstream>
#include "Rules.h"

string ParseString(int value)
{
   stringstream converter;
   converter << value;
   return converter.str();
}

string ResponseFormatter::FormatValidation(string validation)
{
    if(validation == Rules::INVALID)
        return "Sorry, that's not a move. Try providing one of the values from 1 to 9.";
        
    if(validation == Rules::TAKEN)
        return "Sorry, that move has already been taken. Try one that's still open.";
        
    if(validation == Rules::VALID)
        return "Well played, that was a great move!";
        
    return "";
}

string ResponseFormatter::AskForInput()
{
    return "Please provide a move:";
}

string ResponseFormatter::Thinking()
{
    return "The computer is thinking. Please wait.";
}

string ResponseFormatter::GameOver(string winner)
{
    if(winner == Rules::PLAYER)
        return "You won! Holy crap, that really wasn't supposed to be able to happen...";
        
    if(winner == Rules::COMPUTER)
        return "Fail! You lost!";
        
    if(winner == Rules::TIE)
        return "Nice try, but you didn't win. It was a tie!";
        
    return "";
}

string ResponseFormatter::DisplayTicTacToe(Game * game)
{
    string newline = "\n";
    string formatted = "";
    
    formatted += "" + newline;
    formatted += "     |     |     " + newline;
    formatted += "  " + display(game->Moves[0]) + "  |  " + display(game->Moves[1]) + "  |  " + display(game->Moves[2]) + "  " + newline;
    formatted += "     |     |     " + newline;
    formatted += "----- ----- -----" + newline;
    formatted += "     |     |     " + newline;
    formatted += "  " + display(game->Moves[3]) + "  |  " + display(game->Moves[4]) + "  |  " + display(game->Moves[5]) + "  " + newline;
    formatted += "     |     |     " + newline;
    formatted += "----- ----- -----" + newline;
    formatted += "     |     |     " + newline;
    formatted += "  " + display(game->Moves[6]) + "  |  " + display(game->Moves[7]) + "  |  " + display(game->Moves[8]) + "  " + newline;
    formatted += "     |     |     " + newline;
    formatted += "" + newline;
    
    return formatted;
}

string ResponseFormatter::display(Move move)
{
    if(move.Owner == Rules::PLAYER)
        return "X";
        
    if(move.Owner == Rules::COMPUTER)
        return "O";
        
   return ParseString(move.Location);
}