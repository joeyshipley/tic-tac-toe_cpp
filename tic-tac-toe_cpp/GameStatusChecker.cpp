#include "GameStatusChecker.h"

string GameStatusChecker::Check(Board * board)
{
    string winner = Rules::INPROGRESS;
    vector<Cell> cells = board->Cells();
    for(int i = 0; i < cells.size(); i++)
    {
        winner = checkWinnerFromPossibleWinningSets(board, cells[i].X, cells[i].Y);
        if(isGameOver(winner))
            return winner;
    }

    if(!board->HasAvailableMoves())
        return Rules::TIE;
        
    return Rules::INPROGRESS;
}

bool GameStatusChecker::isGameOver(string winner)
{
    return winner != Rules::INPROGRESS;
}

bool GameStatusChecker::shouldContinueChecking(string winner)
{
    return winner == Rules::INPROGRESS;
}

string GameStatusChecker::checkWinnerFromPossibleWinningSets(Board * board, int x, int y)
{
    string winner = Rules::INPROGRESS;

    if(shouldContinueChecking(winner))
        winner = checkWinnerFromRow(board, x, y);

    if(shouldContinueChecking(winner))
        winner = checkWinnerFromColumn(board, x, y);

    if(shouldContinueChecking(winner))
        winner = checkWinnerFromTopLeftStartingDiagonal(board, x, y);

    if(shouldContinueChecking(winner))
        winner = checkWinnerFromBottomLeftStartingDiagonal(board, x, y);

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

    if(ownerHasFullSet(set, Rules::PLAYER))
        return Rules::PLAYER_WON;
    
    if(ownerHasFullSet(set, Rules::COMPUTER))
        return Rules::COMPUTER_WON;
    
    return Rules::INPROGRESS;
}

bool GameStatusChecker::ownerHasFullSet(vector<Cell> set, string owner)
{
    long requiredCount = set.size();
    
    long count = 0;
    for(int i = 0; i < set.size(); i++)
        if(set[i].Owner == owner)
            count += 1;
            
    return count == requiredCount;
}
