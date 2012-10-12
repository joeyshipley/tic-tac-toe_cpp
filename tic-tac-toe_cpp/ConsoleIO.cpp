 #include "ConsoleIO.h"
#include "Rules.h"

void ConsoleIO::Output(string message)
{
    cout << message << endl;
}

int ConsoleIO::Input(string value)
{
    string input;
    getline(cin, input);
    return convertInputToInt(input);
}

int ConsoleIO::convertInputToInt(string input)
{
    int choice = atoi(input.c_str());
    if(choice == 0 && input != "0")
        return Rules::INVALID_INPUT_VALUE;
    return choice;
}