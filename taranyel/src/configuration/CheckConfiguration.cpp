#include "CheckConfiguration.h"
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

bool CheckConfiguration::checkConfig(const string &fileName) {
    ifstream file(fileName, ios::in | ios::binary);
    if (!file.is_open() || !file.good()) {
        file.close();
        return false;
    }

    if (!fillConfig(fileName)){
        return false;
    }

    file.close();
    return true;
}

void CheckConfiguration::createConfig(const char *fileName) {
    remove(fileName);

    ofstream out(fileName, ios::out | ios::binary);

    out << "SCAN 0\n" << "PRINT 1\n" << "IMPORT 2\n" << "EXPORT 3\n" << "= 4\n" << "DELETE 5\n" << "EXIT 6\n" << "HELP 20\n";
    out.close();
    fillConfig(fileName);
}

bool CheckConfiguration::fillConfig(const string &fileName) {
    ifstream file(fileName, ios::in | ios::binary);
    string buff;

    while (getline(file, buff)){

        if (!validate(buff)){
            return false;
        }

        string name;
        string temp;
        int code;

        istringstream iss(buff);

        iss >> name;
        iss >> temp;

        code = stoi(temp);

        this->commands[name] = code;
    }

    if (this->commands.size() != 8){
        file.close();
        return false;
    }
    file.close();
    return true;
}

bool CheckConfiguration::validate(const string& str) {
    if (str.empty()){
        return false;
    }

    istringstream iss(str);
    string temp;
    int i = 0;

    while (i < 2){
        iss >> temp;

        if (i == 1 && !isdigit(temp[0])){
            return false;
        }
        temp.clear();
        i++;
    }

    if (i != 2 || !temp.empty()){
        return false;
    }
    return true;
}
