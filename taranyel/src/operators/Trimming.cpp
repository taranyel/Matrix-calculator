#include "Trimming.h"

Trimming::Trimming() = default;

Operand *Trimming::evaluate() {
    if (variables.size() != 2) {
        return {};
    }

    int rows1, columns1, rows2, columns2;
    vector<vector<double>> matrix1;
    vector<vector<double>> matrix2;

    if (variables[0]->getType() == MATRIX && variables[1]->getType() == MATRIX){
        matrix1 = variables[0]->getValue().second;
        matrix2 = variables[1]->getValue().second;

        rows1 = (int)matrix1.size();
        columns1 = (int)matrix1[0].size();

        rows2 = (int)matrix2.size();
        columns2 = (int)matrix2[0].size();

    } else {
        cout << "Variable is not a matrix!" << endl;
        clearMatrix(matrix1);
        clearMatrix(matrix2);
        return nullptr;
    }

    if (rows1 < rows2 || columns1 < columns2){
        cout << "Variable has an invalid size!" << endl;
        clearMatrix(matrix1);
        clearMatrix(matrix2);
        return nullptr;
    }

    Matrix* resMatrix;
    vector<vector<double>> result(rows2);

    zeroNumber = 0;
    values = 0;

    for (int i = 0; i < rows2; i++){
        for(int j = 0; j < columns2; j++){

            double value = matrix1[i][j];

            if (value == 0){
                zeroNumber++;
            } else {
                values++;
            }

            result[i].push_back(value);
        }
    }

    resMatrix = createMatrix(result);

    clearMatrix(matrix1);
    clearMatrix(matrix2);
    clearMatrix(result);

    return resMatrix;
}


