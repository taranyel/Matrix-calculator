#include "Execute.h"

Execute::Execute(const string &expression, int command) : expression(expression), command(command) {}

Execute::~Execute() {
    for (const auto &i: operands) {
        i.second->clear();
        delete i.second;
    }
    operands.clear();
}

int Execute::evaluate() {
    istringstream stream(expression);
    string name, varNameImpExp;
    int scanning;
    bool varExists = false;

    if (command == EQUAL) {
        stream >> name;
        if (!checkName(name)){
            Error::printError(INVALID_NAME);

        } else if (!evaluateExpr(name)) {
            Error::printError(INVALID_EXPRESSION);
        }
    } else {
        stream >> name >> name;
        if (stream >> varNameImpExp){
            varExists = true;
        }

        if (!checkName(name)){
            Error::printError(INVALID_NAME);
            return 0;
        }

        switch (command) {
            case SCAN:
                scanning = scan(name);
                if (scanning == INVALID_INPUT) {
                    Error::printError(INVALID_INPUT);
                } else if (scanning == VAR_ALREADY_EXISTS) {
                    Error::printError(VAR_ALREADY_EXISTS);
                }
                break;

            case PRINT:
                print(name);
                break;

            case IMPORT:

                if (!varExists){
                    varNameImpExp = "";
                }

                if (!import(name, varNameImpExp)){
                    Error::printError(UNSUCCESSFUL_IMPORT);
                }
                break;

            case EXPORT:
                if (!exportOperands(name, varNameImpExp, operands)){
                    Error::printError(UNSUCCESSFUL_EXPORT);
                }
                break;

            case DELETE:
                deleteVar(name);
                break;

            case EXIT:
                exit();
                return EXIT;

            case HELP:
                printAllOperators();
                break;
        }
    }
    return 0;
}

int Execute::scan(const string &name) {

    if (operands.count(name)) {
        return VAR_ALREADY_EXISTS;
    }

    cout << "Enter your number or matrix in form [[.., ...], ...., [.., ...]]" << endl;

    string buffer;

    try {
        getline(cin, buffer);
    } catch (...){
        return INVALID_INPUT;
    }

    double value = 0;

    if (!ReadOperand::readNumber(buffer, &value)){
        vector<vector<double>> matrix;
        int zeroNumber = 0;
        int values = 0;

        matrix = ReadOperand::readMatrix(buffer, &zeroNumber, &values);

        if (matrix.empty()) {
            return INVALID_INPUT;
        }

        add(name, newEvaluate.createMatrix(zeroNumber, values, matrix));

        ReadOperand::clearMatrix(matrix);

    } else {
        add(name, new Number(value));
    }

    return 0;
}

void Execute::print(const string &name) {
    if (!operands.count(name)) {
        Error::printError(VAR_DOES_NOT_EXIST);
    } else {
        cout << "Your variable " + name + ": "<< endl;
        operands.at(name)->print(cout);
    }
}

void Execute::deleteVar(const string &name) {
    if (!operands.count(name)) {
        Error::printError(VAR_DOES_NOT_EXIST);
    } else {
        delete operands.at(name);
        operands.erase(name);
        cout << "Successfully deleted!" << endl;
    }
}

void Execute::exit() {
    cout << "See you soon!" << endl;
}

void Execute::add(const string &name, Operand *operand) {
    operands.insert({name, operand});
}

bool Execute::evaluateExpr(const string &name) {
    istringstream iss(expression);

    Operand *result;
    string temp;
    string toRead;

    iss >> temp >> temp;
    temp.clear();

    result = newEvaluate.evaluate(operands, newEvaluate.operators, iss);

    if (!result){
        return false;
    }

    if (operands.count(name)) {
        delete operands.at(name);
        operands.erase(name);
    }

    add(name, result);

    print(name);

    return true;
}

void Execute::setExpression(const string &newExpression) {
    expression = newExpression;
}

void Execute::setCommand(int newCommand) {
    command = newCommand;
}

void Execute::printAllOperators() {
    cout << endl;
    cout << "Valid operators:" << endl;
    for (const auto& i : newEvaluate.operators){
        cout << i.first << endl;
    }
}

bool Execute::checkName(const string& name) {
    if (newEvaluate.operators.count(name)){
        return false;
    }
    return true;
}

bool Execute::import(const string& fileName, const string& varName) {
    Import import(fileName, varName);
    map<string, Operand*> imported = import.import();

    if (imported.empty()){
        return false;
    }

    for (const auto& i : imported){
        if (operands.count(i.first)){
            delete operands.at(i.first);
            operands.erase(i.first);
        }
        add(i.first, i.second);
    }
    return true;
}

bool Execute::exportOperands(const string& fileName, const string& varName, const map<string, Operand *>& operandsExp) {
    Export exportOp(fileName, varName);

    if (!exportOp.exportOperands(operands)){
        return false;
    }

    return true;
}

