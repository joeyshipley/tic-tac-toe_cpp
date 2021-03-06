#ifndef __tic_tac_toe_cpp__GameStatusChecker__
#define __tic_tac_toe_cpp__GameStatusChecker__

#include "GameStatusAlgorithm.h"
#include "Rules.h"
#include "DTO.h"

using namespace std;

class GameStatusChecker : public GameStatusAlgorithm
{
    public:
        virtual ~GameStatusChecker() {}
        virtual string Check(Board * board);
        
    private:
        string checkWinnerFromPossibleWinningSets(Board * board, int x, int y);
        string checkWinnerFromRow(Board * board, int x, int y);
        string checkWinnerFromColumn(Board * board, int x, int y);
        string checkWinnerFromTopLeftStartingDiagonal(Board * board, int x, int y);
        string checkWinnerFromBottomLeftStartingDiagonal(Board * board, int x, int y);
        vector<Cell> buildSetFrom(Board * board, Coord first, Coord second, Coord third);
        string checkWinnerFromSet(vector<Cell> set);
        bool shouldContinueChecking(string winner);
        bool isGameOver(string winner);
        bool ownerHasFullSet(vector<Cell> set, string owner);
};

#endif /* defined(__tic_tac_toe_cpp__GameStatusChecker__) */
