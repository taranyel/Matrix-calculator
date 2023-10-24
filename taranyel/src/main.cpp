#include <fstream>
#include "input/Input.h"

using namespace std;

int main() {
    CheckConfiguration configuration;
    if (!configuration.checkConfig("examples/commands.txt")){
        configuration.createConfig("examples/commands.txt");
    }

    Input input(configuration);
    Execute execute("", -1);

    cout << "Hello! It is a matrix calculator. Reminder: you can only set valid variable names." << endl;
    cout << "Invalid are: the names of operators and commands" << endl;
    cout << "If you want to know all rules, write: HELP" << endl;
    cout << endl;

    while (true){
        cout << "Enter your command:" << endl;

        if (!input.readInput()){
            Error::printError(INVALID_INPUT);
            continue;
        }

        switch (input.checkInput()) {
            case UNKNOWN_COMMAND:
                Error::printError(UNKNOWN_COMMAND);
                continue;
            case INVALID_COMMAND_ORDER:
                Error::printError(INVALID_COMMAND_ORDER);
                continue;
            case INCOMPLETE_COMMAND:
                Error::printError(INCOMPLETE_COMMAND);
                continue;
            case TOO_MUCH_VARIABLES_ENTERED:
                Error::printError(TOO_MUCH_VARIABLES_ENTERED);
                continue;
            case INVALID_INPUT:
                Error::printError(INVALID_INPUT);
                continue;
            case INVALID_NAME:
                Error::printError(INVALID_NAME);
                continue;
        }

        execute.setExpression(input.buffer);
        execute.setCommand(input.command);

        int output = execute.evaluate();

        if (output == INVALID_NAME){
            Error::printError(INVALID_NAME);
            continue;
        } else if (output == EXIT){
            return 0;
        }
    }

    return 0;
}
