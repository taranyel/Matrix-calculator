
#include "Merging.h"

Merging::Merging() = default;

Operand* Merging::evaluate() {
    if (variables.size() != 2){
        return {};
    }

    int columns1, columns2, rows1, rows2;
    vector<vector<double>> m1;
    vector<vector<double>> m2;

    if (variables[0]->getType() == MATRIX && variables[1]->getType() == MATRIX){
        m1 = variables[0]->getValue().second;
        m2 = variables[1]->getValue().second;

        rows1 = (int)m1.size();
        rows2 = (int)m2.size();

        columns1 = (int)m1[0].size();
        columns2 = (int)m2[0].size();

    } else {
        cout << "Variable is not a matrix!" << endl;
        clearMatrix(m1);
        clearMatrix(m2);
        return nullptr;
    }

    if (columns1 != columns2){
        cout << "Variable has an invalid size!" << endl;
        clearMatrix(m1);
        clearMatrix(m2);
        return nullptr;
    }

    Matrix* resMatrix;
    vector<vector<double>> result(rows1 + rows2);

    zeroNumber = 0;
    values = 0; 
    int k = 0;

    for (int i = 0; i < rows1; i++){
        for (int j = 0; j < columns1; j++){

            double value = m1[i][j];

            if (value == 0){
                zeroNumber++;
            } else {
                values++;
            }

            result[k].push_back(value);
        }
        k++;
    }

    for (int i = 0; i < rows2; i++){
        for (int j = 0; j < columns2; j++){

            double value = m2[i][j];

            if (value == 0){
                zeroNumber++;
            } else {
                values++;
            }

            result[k].push_back(value);
        }
        k++;
    }

    resMatrix = createMatrix(result);

    clearMatrix(m1);
    clearMatrix(m2);
    clearMatrix(result);

    return resMatrix;
}

