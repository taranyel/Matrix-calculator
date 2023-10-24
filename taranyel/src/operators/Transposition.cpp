#include "Transposition.h"

Transposition::Transposition() = default;

Operand* Transposition::evaluate() {
    if (variables.size() != 1){
        return nullptr;
    }

    vector<vector<double>> matrix;

    if (variables[0]->getType() == MATRIX){
        matrix = variables[0]->getValue().second;
    } else {
        cout << "Variable is not a matrix!" << endl;
        clearMatrix(matrix);
        return nullptr;
    }

    Matrix* result;
    int rows = (int)matrix.size();
    int columns = (int)matrix[0].size();

    vector<vector<double>> transposed(columns);
    
    zeroNumber = 0;
    values = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {

            double value = matrix[i][j];

            if (value == 0){
                zeroNumber++;
            } else {
                values++;
            }
            transposed[j].push_back(value);
        }
    }
    
    result = createMatrix(transposed);

    clearMatrix(matrix);
    clearMatrix(transposed);

    return result;
}


