#include "NegaMaxAi.h"
#include "Cell.h"
#include "Rules.h"

int NegaMaxAi::Next(Board * board)
{
    vector<Cell> cells = board->Cells();
    
    for(int i = 0; i < cells.size(); i++)
        if(cells[i].Owner == Rules::NONE)
            return cells[i].Value;
            
    return -1;
};