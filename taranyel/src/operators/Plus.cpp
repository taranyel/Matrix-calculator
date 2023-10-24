#include "Plus.h"

Plus::Plus() = default;

Operand *Plus::evaluate() {

    if (variables.size() != 2) {
        return nullptr;
    }

    int rows1, columns1, rows2, columns2;
    vector<vector<double>> m1;
    vector<vector<double>> m2;

    if (variables[0]->getType() == MATRIX && variables[1]->getType() == MATRIX){
        m1 = variables[0]->getValue().second;
        m2 = variables[1]->getValue().second;

        rows1 = (int)m1.size();
        columns1 = (int)m1[0].size();

        rows2 = (int)m2.size();
        columns2 = (int)m2[0].size();

    } else if (variables[0]->getType() == NUMBER && variables[1]->getType() == NUMBER){
        return new Number(variables[0]->getValue().first + variables[1]->getValue().first);
    } else {
        cout << "Variable has an invalid type!" << endl;
        clearMatrix(m1);
        clearMatrix(m2);
        return nullptr;
    }

    if (rows1 != rows2 || columns1 != columns2){
        cout << "Variable has an invalid size!" << endl;
        clearMatrix(m1);
        clearMatrix(m2);
        return nullptr;
    }

    zeroNumber = 0;
    values = 0;

    Matrix *resMatrix;
    vector<vector<double>> result(rows1);

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            double value = m1[i][j] + m2[i][j];

            if (value == 0) {
                zeroNumber++;
            } else {
                values++;
            }
            result[i].push_back(value);
        }
    }

    resMatrix = createMatrix(result);

    clearMatrix(m1);
    clearMatrix(m2);
    clearMatrix(result);

    return resMatrix;
}



