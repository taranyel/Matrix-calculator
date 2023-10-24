#include "DenseMatrix.h"

DenseMatrix::DenseMatrix(int rows, int columns, const vector<vector<double>> &matrix) : Matrix(rows,
                                                                                               columns),
                                                                                               matrix(matrix) {}

DenseMatrix::~DenseMatrix() {
}

void DenseMatrix::print(ostream &stream) {
    for (int i = 0; i < getRows(); i++){
        for (int j = 0; j < getColumns(); j++){
            if (matrix[i][j] == 0){
                matrix[i][j] = 0;
            }
            stream << matrix[i][j] << " ";
        }
        stream << endl;
    }
}

vector<vector<double>> DenseMatrix::getMatrix() {
    return matrix;
}

void DenseMatrix::clear(){
    for (int i = 0; i < getRows(); i++){
        matrix[i].clear();
    }
    matrix.clear();
}

