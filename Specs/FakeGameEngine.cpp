#include "FakeGameEngine.h"

FakeGameEngine::FakeGameEngine()
{
    StartTimesCalled = 0;
    PerformTurnTimesCalled = 0;
}

void FakeGameEngine::Start()
{
    StartTimesCalled += 1;
}

Game * FakeGameEngine::PerformTurn(int input)
{
    PerformTurnTimesCalled += 1;
    return returnForPerformTurn;
}

Game * FakeGameEngine::CurrentState()
{
    return returnForCurrentState;
}

bool FakeGameEngine::IsGameOver()
{
    bool isOver = returnForIsGameOver.front();
    
    vector<int> newReturnSet;
    for(int i = 1; i < returnForIsGameOver.size(); i++)
        newReturnSet.push_back(returnForIsGameOver[i]);
    returnForIsGameOver = newReturnSet;
    
    return isOver;
}

void FakeGameEngine::AndReturnsForCurrentState(Game * state)
{
    returnForCurrentState = state;
}

void FakeGameEngine::AndReturnsForPerformTurn(Game * response)
{
    returnForPerformTurn = response;
}

void FakeGameEngine::AndReturnsForIsGameOver(bool isOver)
{
    returnForIsGameOver.push_back(isOver);
}
