#include "Export.h"

Export::Export(const string &fileName, const string &varName) : fileName(fileName), varName(varName) {}

bool Export::exportOperands(const map<string, Operand *> &operands) {

    if (varName.empty()) {
        if (!exportAll(operands)) {
            return false;
        }
    } else {
        if (!exportOne(operands)) {
            return false;
        }
    }

    return true;
}

bool Export::exportAll(const map<string, Operand *> &operands) {
    ofstream out(fileName, ios::out | ios::binary);

    if (out.is_open()) {
        if (out.good()) {
            for (auto i: operands) {
                out << i.first + " = ";
                if (i.second->getType() == MATRIX){
                    out << endl;
                }
                i.second->print(out);
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
    return true;
}

bool Export::exportOne(const map<string, Operand *> &operands) {
    ofstream out(fileName, ios::out | ios::binary);

    if (out.is_open()) {
        if (out.good()) {
            out << varName + " = ";
            if (operands.at(varName)->getType() == MATRIX){
                    out << endl;
            }
            operands.at(varName)->print(out);
        } else {
            return false;
        }
    } else {
        return false;
    }
    return true;
}

