#include "GameStatusChecker.h"

string GameStatusChecker::Check(Board * board)
{
    if(!board->HasAvailableMoves())
        return Rules::TIE;
        
    string winner = Rules::NONE;
    vector<Cell> cells = board->Cells();
    for(int i = 0; i < cells.size(); i++)
    {
        if(winner == Rules::NONE)
            winner = checkWinnerFromRow(board, cells[i].X, cells[i].Y);
            
        if(winner == Rules::NONE)
            winner = checkWinnerFromColumn(board, cells[i].X, cells[i].Y);
            
        if(winner == Rules::NONE)
            winner = checkWinnerFromTopLeftStartingDiagonal(board, cells[i].X, cells[i].Y);
            
        if(winner == Rules::NONE)
            winner = checkWinnerFromBottomLeftStartingDiagonal(board, cells[i].X, cells[i].Y);
    }
    
    return winner;
}

string GameStatusChecker::checkWinnerFromRow(Board * board, int x, int y)
{
    vector<Cell> set = buildSetFrom(board, * DTO::BuildCoord(x, y - 1), * DTO::BuildCoord(x, y), * DTO::BuildCoord(x, y + 1));
    return checkWinnerFromSet(set);
}

string GameStatusChecker::checkWinnerFromColumn(Board * board, int x, int y)
{
    vector<Cell> set = buildSetFrom(board, * DTO::BuildCoord(x - 1, y), * DTO::BuildCoord(x, y), * DTO::BuildCoord(x + 1, y));
    return checkWinnerFromSet(set);
}

string GameStatusChecker::checkWinnerFromTopLeftStartingDiagonal(Board * board, int x, int y)
{
    vector<Cell> set = buildSetFrom(board, * DTO::BuildCoord(x - 1, y - 1), * DTO::BuildCoord(x, y), * DTO::BuildCoord(x + 1, y + 1));
    return checkWinnerFromSet(set);
}

string GameStatusChecker::checkWinnerFromBottomLeftStartingDiagonal(Board * board, int x, int y)
{
    vector<Cell> set = buildSetFrom(board, * DTO::BuildCoord(x + 1, y - 1), * DTO::BuildCoord(x, y), * DTO::BuildCoord(x - 1, y + 1));
    return checkWinnerFromSet(set);
}

vector<Cell> GameStatusChecker::buildSetFrom(Board * board, Coord first, Coord second, Coord third)
{
    vector<Cell> set = vector<Cell>(3);
    set[0] = board->FindCellByCoordinates(first.X, first.Y);
    set[1] = board->FindCellByCoordinates(second.X, second.Y);
    set[2] = board->FindCellByCoordinates(third.X, third.Y);
    return set;
}

string GameStatusChecker::checkWinnerFromSet(vector<Cell> set)
{
    long required = set.size();
    long validCount = 0;
    long playerCount = 0;
    long computerCount = 0;
    
    for(int i = 0; i < set.size(); i++)
    {
        if(set[i].IsValid)
            validCount++;
        if(set[i].Owner == Rules::PLAYER)
            playerCount++;
        if(set[i].Owner == Rules::COMPUTER)
            computerCount++;
    }
    
    if(playerCount == required)
        return Rules::PLAYER;
    
    if(computerCount == required)
        return Rules::COMPUTER;

    return Rules::NONE;
}
