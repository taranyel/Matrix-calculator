#include "Multiplying.h"

Multiplying::Multiplying() = default;

Operand *Multiplying::evaluate() {
    if (variables.size() != 2) {
        return nullptr;
    }

    int columns1, rows2;
    double value;
    vector<vector<double>> m1;
    vector<vector<double>> m2;
    vector<vector<double>> result;
    Operand *resMatrix;

    if (variables[0]->getType() == NUMBER && variables[1]->getType() == NUMBER) {
        return new Number(variables[0]->getValue().first * variables[1]->getValue().first);
    } else if (variables[0]->getType() == MATRIX && variables[1]->getType() == MATRIX) {
        m1 = variables[0]->getValue().second;
        m2 = variables[1]->getValue().second;

        columns1 = (int) m1[0].size();
        rows2 = (int) m2.size();

        if (columns1 != rows2) {
            cout << "Variable has an invalid size!" << endl;
            clearMatrix(m1);
            clearMatrix(m2);
            clearMatrix(result);
            return nullptr;
        }

        result = matrixMulMatrix(m1, m2);
        resMatrix = createMatrix(result);

    } else if (variables[0]->getType() == MATRIX && variables[1]->getType() == NUMBER) {
        m1 = variables[0]->getValue().second;
        value = variables[1]->getValue().first;

        result = numberMulMatrix(value, m1);
        resMatrix = createMatrix(result);
    } else {
        m1 = variables[1]->getValue().second;
        value = variables[0]->getValue().first;

        result = numberMulMatrix(value, m1);
        resMatrix = createMatrix(result);
    }

    clearMatrix(m1);
    clearMatrix(m2);
    clearMatrix(result);

    return resMatrix;
}

vector<vector<double>> Multiplying::numberMulMatrix(double number, vector<vector<double>> matrix) {
    vector<vector<double>> result(matrix.size());

    zeroNumber = 0;
    values = 0;

    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[0].size(); j++) {
            double value = matrix[i][j] * number;

            if (value == 0){
                zeroNumber++;
            } else {
                values++;
            }
            result[i].push_back(value);
        }
    }

    return result;
}

vector<vector<double>> Multiplying::matrixMulMatrix(vector<vector<double>> matrix1, vector<vector<double>> matrix2) {

    vector<vector<double>> result(matrix1.size());

    zeroNumber = 0;
    values = 0;

    for (size_t i = 0; i < matrix1.size(); i++) {
        for (size_t j = 0; j < matrix2[0].size(); j++) {

            result[i].push_back(0);

            for (size_t k = 0; k < matrix1[0].size(); k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            
            double value = result[i][j];
            if (value == 0){
                zeroNumber++;
            } else {
                values++;
            }
        }
    }

    return result;
}

