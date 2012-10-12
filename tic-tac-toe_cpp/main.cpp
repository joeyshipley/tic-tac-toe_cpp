#include <iostream>

#include "GameEngine.h"
#include "Board.h"
#include "InputValidator.h"
#include "GameStatusAlgorithm.h"
#include "ComputerAiAlgorithm.h"
#include "ThreeByThreeBoard.h"
#include "PlayerInputValidator.h"
#include "GameStatusChecker.h"
#include "NegaMaxAi.h"

using namespace std;

int main(int argc, char **argv)
{
    Board * board = new ThreeByThreeBoard();
    InputValidator * validator = new PlayerInputValidator();
    GameStatusAlgorithm * status = new GameStatusChecker();
    ComputerAiAlgorithm * ai = new NegaMaxAi(status);
    
    cout << "Welcome to TTT" << endl;

    GameEngine engine = * new GameEngine(board, validator, status, ai);
    
    engine.Start();
    
    string input;
    getline(cin, input);
    int choice = atoi(input.c_str());
    
    Game response1 = engine.PerformTurn(choice);
    cout << response1.Message << endl;
    
    Game response2 = engine.PerformTurn(2);
    cout << response2.Message << endl;
    
    
    
    delete board;
    delete validator;
    delete status;
    delete ai;
    
    return 0;
}