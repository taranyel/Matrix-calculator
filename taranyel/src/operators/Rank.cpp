#include "Rank.h"

Rank::Rank() = default;

Operand* Rank::evaluate() {
    if (variables.size() != 1) {
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

    Number* result;
    int noZeroRows = 0;
    
    matrix = gaussMethod(matrix);
    
    for (size_t i = 0; i < matrix.size(); i++){
        for (size_t j = 0; j < matrix[0].size(); j++){
            if (matrix[i][j] != 0){
                noZeroRows++;
                break;
            }
        }
    }

    result = new Number(noZeroRows);

    clearMatrix(matrix);
    
    return result;
}
