#include "GaussMethod.h"

GaussMethod::GaussMethod() = default;

Operand* GaussMethod::evaluate() {
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

    matrix = gaussMethod(matrix);
    result = createMatrix(matrix);
    
    clearMatrix(matrix);
    
    return result;
}

vector<vector<double>> GaussMethod::gaussMethod(vector<vector<double>> matrix) {
    int rows = (int)matrix.size();
    int columns = (int)matrix[0].size();

    for (int i = 0; i < rows; i++) {
        int pivot = i;

        /// Find the pivot element in the current column
        while (pivot < columns && matrix[i][pivot] == 0) {
            pivot++;
        }

        /// If pivot is beyond the number of columns, exit the loop
        if (pivot >= columns) {
            break;
        }

        /// Swap the rows if the pivot is not in the current row
        if (pivot != i) {
            swap(matrix[i], matrix[pivot]);
        }

        zeroNumber = 0;
        values = 0;

        /// Perform row operations to make the lower triangular elements zero
        for (int j = i + 1; j < rows; j++) {

            /// Calculate the ratio between the current element and the pivot element
            double ratio = matrix[j][i] / matrix[i][i];
            for (int k = i; k < columns; k++) {

                /// Subtract the product of the ratio and the corresponding element in the pivot row
                matrix[j][k] -= ratio * matrix[i][k];

                double value = matrix[j][k];

                if (value == 0){
                    zeroNumber++;
                } else {
                    values++;
                }
            }
        }
    }
    
    return matrix;
}
