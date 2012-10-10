#include "PlayerInputValidator.h"

string PlayerInputValidator::Check(int input, Board * board)
{
    Cell cell = board->FindCell(input);
    
    if(!cell.IsValid)
        return Rules::INVALID;
    
    if(cell.Owner != Rules::NONE)
        return Rules::TAKEN;
        
    return Rules::VALID;
}