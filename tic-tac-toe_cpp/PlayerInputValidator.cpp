//
//  PlayerInputValidator.cpp
//  tic-tac-toe_cpp
//
//  Created by Joey Shipley on 10/10/12.
//  Copyright (c) 2012 Joey Shipley. All rights reserved.
//

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