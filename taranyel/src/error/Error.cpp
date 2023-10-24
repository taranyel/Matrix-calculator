#include "Error.h"

using namespace std;

void Error::printError(int errorCode) {
    switch (errorCode) {
        case UNKNOWN_COMMAND:
            cout << "Unknown command!" << endl;
            break;
        case VAR_DOES_NOT_EXIST:
            cout << "Variable does not exist!" << endl;
            break;
        case VAR_ALREADY_EXISTS:
            cout << "Variable already exists" << endl;
            break;
        case INVALID_INPUT:
            cout << "Invalid input!" << endl;
            break;
        case INVALID_EXPRESSION:
            cout << "Invalid expression!" << endl;
            break;
        case INVALID_COMMAND_ORDER:
            cout << "Invalid command order!" << endl;
            break;
        case INCOMPLETE_COMMAND:
            cout << "Incomplete command!" << endl;
            break;
        case TOO_MUCH_VARIABLES_ENTERED:
            cout << "Too much variables entered!" << endl;
            break;
        case INVALID_NAME:
            cout << "Invalid name entered!" << endl;
            break;
        case UNSUCCESSFUL_IMPORT:
            cout << "Unsuccessful import!" << endl;
            break;
        case UNSUCCESSFUL_EXPORT:
            cout << "Unsuccessful export!" << endl;
            break;
        default:
            break;
    }
}
