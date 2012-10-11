#ifndef __tic_tac_toe_cpp__GameStatusChecker__
#define __tic_tac_toe_cpp__GameStatusChecker__

#include "GameStatusAlgorithm.h"
#include "Rules.h"

using namespace std;

struct coord
{
    int X;
    int Y;
};

class GameStatusChecker : public GameStatusAlgorithm
{
    public:
        virtual string Check(Board * board);
        
    private:
        string checkWinnerFromRow(Board * board, int x, int y);
        string checkWinnerFromColumn(Board * board, int x, int y);
        string checkWinnerFromTopLeftStartingDiagonal(Board * board, int x, int y);
        string checkWinnerFromBottomLeftStartingDiagonal(Board * board, int x, int y);
        coord coordinate(int x, int y);
        vector<Cell> buildSetFrom(Board * board, coord first, coord second, coord third);
        string checkWinnerFromSet(vector<Cell> set);
};

#endif /* defined(__tic_tac_toe_cpp__GameStatusChecker__) */