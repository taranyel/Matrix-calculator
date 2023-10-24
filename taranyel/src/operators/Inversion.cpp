#include "Inversion.h"

Inversion::Inversion() = default;

vector<vector<double>> Inversion::getCofactor(const vector<vector<double>>& matrix) {
    int size = (int)matrix.size();
    vector<vector<double>> cofactor;

    for (int i = 0; i < size; ++i) {
        cofactor.emplace_back();
        for (int j = 0; j < size; ++j) {
            
            /// Get the submatrix by excluding the ith row and the jth column
            vector<vector<double>> minor = subMatrix(matrix, i, j);

            /// Determine the sign based on the sum of the row and column indices
            int sign = (i + j) % 2 == 0 ? 1 : -1;

            /// Calculate the determinant of the submatrix and multiply it by the sign
            cofactor[i].push_back(sign * calculateDeterminant(minor));
        }
    }
    return cofactor;
}

Operand* Inversion::evaluate() {

    if (variables.size() != 1){
        return {};
    }

    int rows, columns;
    vector<vector<double>> matrix;

    if (variables[0]->getType() == MATRIX){
        matrix = variables[0]->getValue().second;
        rows = (int)matrix.size();
        columns = (int)matrix[0].size();

    } else {
        cout << "Variable is not a matrix!" << endl;
        matrix.clear();
        return nullptr;
    }

    if (rows != columns) {
        cout << "The matrix is not square!" << endl;
        clearMatrix(matrix);
        return nullptr;
    }

    zeroNumber = 0;
    values = 0;

    int size = (int)matrix.size();
    vector<vector<double>> inverseMatrix;
    double det = calculateDeterminant(matrix);

    if (det == 0) {
        cout << "Matrix is not invertible." << endl;
        clearMatrix(matrix);
        inverseMatrix.clear();
        return nullptr;
    }

    vector<vector<double>> cofactorMatrix = getCofactor(matrix);
    Matrix* result;

    for (int i = 0; i < size; ++i) {
        inverseMatrix.emplace_back();
        for (int j = 0; j < size; ++j) {

            double value = cofactorMatrix[j][i] / det;

            if (value == 0){
                zeroNumber++;
            } else {
                values++;
            }

            inverseMatrix[i].push_back(value);
        }
    }

    result = createMatrix(inverseMatrix);

    clearMatrix(inverseMatrix);
    clearMatrix(cofactorMatrix);
    clearMatrix(matrix);

    return result;
}
