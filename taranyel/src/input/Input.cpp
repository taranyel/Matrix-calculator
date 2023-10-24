#include "Input.h"
#include <fstream>

using namespace std;

bool Input::readInput() {
    try {
        getline(cin, buffer);
    } catch (...) {
        return false;
    }

    if (buffer.empty()){
        buffer = "EXIT";
    }
    return true;
}

int Input::checkInput() {
    istringstream iss(buffer);
    string temp;
    string name;
    int i = 0;

    while (iss >> temp){

        if (!this->commands.count(temp)){
            if (i == 0){
                i++;
                temp.clear();
                continue;
            }
            return UNKNOWN_COMMAND;

        } else {

            if (i == 0 && temp == "="){
                return INVALID_COMMAND_ORDER;
            }

            if (i == 1 && temp != "="){
                return INVALID_COMMAND_ORDER;
            }

            if (!(iss >> name) && temp != "EXIT" && temp != "HELP"){
                return INCOMPLETE_COMMAND;
            }

            if (commands.count(name) && temp != "IMPORT" && temp != "EXPORT"){
                return INVALID_NAME;
            }

            if (!name.empty() && (temp == "EXIT" || temp == "HELP")){
                return TOO_MUCH_VARIABLES_ENTERED;
            }

            if ((iss >> name) && temp != "=" && temp != "EXPORT" && temp != "IMPORT"){
                return TOO_MUCH_VARIABLES_ENTERED;
            }

            if ((iss >> name) && (temp == "IMPORT" || temp == "EXPORT")){
                return TOO_MUCH_VARIABLES_ENTERED;
            }

            if (temp == "HELP"){
                printAllCommands();
            }

            command = this->commands[temp];
            return true;
        }
    }

    return INVALID_INPUT;
}

Input::Input(const Commands& configuration) {
    this->commands = configuration.commands;
    command = -1;
}

void Input::printAllCommands() {
    cout << "Valid commands:" << endl;
    for (const auto& i : commands){
        if (i.first == "="){
            cout << "[variable name] " << i.first << " [expression]" << endl;
        } else {
            cout << i.first;
            if (i.first != "EXIT" && i.first != "HELP"){

                if (i.first == "EXPORT" || i.first == "IMPORT"){
                    cout << " [file name]" << endl;
                    cout << "You can also add [variable name] parameter if you want to export/import only one variable." << endl;
                } else {
                    cout << " [variable name]" << endl;
                }
            } else {
                cout << endl;
            }
        }
    }
    cout << endl;
}

