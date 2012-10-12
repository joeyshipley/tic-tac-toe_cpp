#ifndef __tic_tac_toe_cpp__FakeGameEngine__
#define __tic_tac_toe_cpp__FakeGameEngine__

#include <iostream>
#include "Engine.h"
#include "DTO.h"

using namespace std;

class FakeGameEngine : public Engine
{
    public:
        virtual void Start();
        virtual Game * PerformTurn(int input);
        virtual Game * CurrentState();
        virtual bool IsGameOver();

    public:
        FakeGameEngine();
        int StartTimesCalled;
        int PerformTurnTimesCalled;
        void AndReturnsForPerformTurn(Game * response);
        void AndReturnsForCurrentState(Game * state);
        void AndReturnsForIsGameOver(bool isOver);

    private:
        Game * returnForPerformTurn;
        Game * returnForCurrentState;
        vector<int> returnForIsGameOver;
};

#endif /* defined(__tic_tac_toe_cpp__FakeGameEngine__) */
