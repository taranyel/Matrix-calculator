#include "Evaluate.h"

Operand *Evaluate::evaluate(map<string, Operand *> operands, map<string, Operator *> operators, istringstream &iss) {

    string temp, toRead;
    Operand *result;
    vector<Operand *> variables;
    vector<Operand*> stack;
    vector<Operand *> garbage;

    while (iss >> temp) {

        if (operands.count(temp)) {
            if (dynamic_cast<DenseMatrix *>(operands.at(temp))) {
                result = new DenseMatrix(operands.at(temp)->getValue().second.size(), operands.at(temp)->getValue().second[0].size(), operands.at(temp)->getValue().second);

            } else if (dynamic_cast<SparseMatrix *>(operands.at(temp))) {
                SparseMatrix *newMatrix = new SparseMatrix(operands.at(temp)->getValue().second.size(), operands.at(temp)->getValue().second[0].size());
                newMatrix->createSparseMatrixCSR(operands.at(temp)->getValue().second);
                result = newMatrix;

            } else {
                result = new Number(operands.at(temp)->getValue().first);
            }
            
            stack.push_back(result);
            garbage.push_back(result);

        } else if (operators.count(temp)) {
            bool check = true;

            if (temp == "+" || temp == "-" || temp == "MUL" || temp == "ADD" || temp == "TRIM") {
                if (stack.size() < 2) {
                    check = false;
                } else {
                    variables.push_back(stack[stack.size() - 1]);
                    stack.pop_back();
                    variables.push_back(stack[stack.size() - 1]);
                    stack.pop_back();
                }

            } else if (temp == "DET" || temp == "GAUSS" || temp == "INV" || temp == "RANK" || temp == "TRANS") {
                if (stack.empty()) {
                    check = false;
                } else {
                    variables.push_back(stack[stack.size() - 1]);
                    stack.pop_back();
                }
            }

            if (!check) {

                clearVectors(garbage, variables, stack);
                return nullptr;
            }

            reverse(variables.begin(), variables.end());
            operators.at(temp)->setVariables(variables);
            result = operators.at(temp)->evaluate();

            if (!result) {

                clearVectors(garbage, variables, stack);
                return nullptr;
            }

            stack.push_back(result);
            garbage.push_back(result);
            variables.clear();

        } else if (temp[0] == '[') {
            toRead += temp;

            while (toRead[toRead.size() - 2] != ']' || toRead[toRead.size() - 1] != ']') {
                iss >> temp;
                toRead += temp;
            }

            int zeroNumber = 0;
            int values = 0;

            vector<vector<double>> tempMatrix;
            tempMatrix = ReadOperand::readMatrix(toRead, &zeroNumber, &values);

            if (tempMatrix.empty()) {
                ReadOperand::clearMatrix(tempMatrix);
                clearVectors(garbage, variables, stack);
                return nullptr;
            }

            result = createMatrix(zeroNumber, values, tempMatrix);

            stack.push_back(result);
            garbage.push_back(result);

            ReadOperand::clearMatrix(tempMatrix);
        } else {

            double value = 0;
            if (ReadOperand::readNumber(temp, &value)) {

                result = new Number(value);
                stack.push_back(result);
                garbage.push_back(result);

            } else {

                clearVectors(garbage, variables, stack);
                return nullptr;
            }
        }
        toRead.clear();
        temp.clear();
    }

    if (stack.size() != 1) {

        clearVectors(garbage, variables, stack);
        return {};
    }

    for (auto i : garbage){
        if (i != stack[0]){
            delete i;
        }
    }

    garbage.clear();
    variables.clear();

    return stack[stack.size() - 1];
}


Matrix *Evaluate::createMatrix(int zeroNumber, int values, vector<vector<double>> matrix) {
    Matrix *result;

    if (zeroNumber > values) {
        SparseMatrix *sparseMatrix = new SparseMatrix((int) matrix.size(), (int) matrix[0].size());
        sparseMatrix->createSparseMatrixCSR(matrix);
        result = sparseMatrix;
    } else {
        DenseMatrix *denseMatrix = new DenseMatrix((int) matrix.size(), (int) matrix[0].size(), matrix);
        result = denseMatrix;
    }

    return result;
}

Evaluate::Evaluate() {
    fillOperators();
}

void Evaluate::clearVectors(vector<Operand*> garbage, vector<Operand*> variables, vector<Operand*> stack){
    for (auto i: garbage) {
        delete i;
    }

    stack.clear();
    garbage.clear();
    variables.clear();
}