#include "Determinant.h"

Determinant::Determinant() = default;

Operand* Determinant::evaluate() {
    if (variables.size() != 1){
        return nullptr;
    }

    vector<vector<double>> matrix;
    int rows, columns;

    if (variables[0]->getType() == MATRIX){
       matrix = variables[0]->getValue().second;
       rows = (int)variables[0]->getValue().second.size();
       columns = (int)variables[0]->getValue().second[0].size();
    } else {
        cout << "Variable is not a matrix!" << endl;
        clearMatrix(matrix);
        return nullptr;
    }

    if (rows != columns){
        cout << "The matrix is not square!" << endl;
        clearMatrix(matrix);
        return nullptr;
    }
    
    Number* result;
    result = new Number(calculateDeterminant(matrix));

    clearMatrix(matrix);
    return result;
}

double Determinant::calculateDeterminant(const vector<vector<double>> &matrix) {
    int size = (int)matrix.size();

    /// Base case: matrix is a 1x1 matrix, return the single element as determinant
    if (size == 1) {
        return matrix[0][0];

        /// Base case: matrix is a 2x2 matrix, return the determinant using the formula
    } else if (size == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    double det = 0;

    /// Iterate through the first row of the matrix
    for (int j = 0; j < size; ++j) {

        /// Get the submatrix by excluding the first row and the jth column
        vector<vector<double>> minor = subMatrix(matrix, 0, j);

        /** Calculate the determinant of the submatrix and multiply it by the corresponding element from the first row
         Add or subtract the result to the determinant based on the sign determined by the parity of the column index
        */
        det += matrix[0][j] * calculateDeterminant(minor) * (j % 2 == 0 ? 1 : -1);
    }
    return det;
}

vector<vector<double>> Determinant::subMatrix( vector<vector<double>> matrix, int row, int col) {
    vector<vector<double>> minor;

    int s = (int)matrix.size() - 1;

    /// Iterate through the rows of the submatrix
    for (int i = 0; i < s; ++i) {
        minor.emplace_back();

        /// Iterate through the columns of the submatrix
        for (int j = 0; j < s; ++j) {

            /// Adjust the row index based on the removed row
            int rowIndex = i >= row ? i + 1 : i;

            /// Adjust the row index based on the removed column
            int colIndex = j >= col ? j + 1 : j;

            /// Add the element to the submatrix
            minor[i].push_back(matrix[rowIndex][colIndex]);
        }
    }
    return minor;
}

