#include "SparseMatrix.h"

SparseMatrix::SparseMatrix(int rows, int columns) : Matrix(rows, columns) {}

SparseMatrix SparseMatrix::createSparseMatrixCSR(const vector<vector<double>> &matrix) {
    rowPointers.push_back(0);
    int nonZeroElements = 0;

    for (int i = 0; i < getRows(); i++) {
        for (int j = 0; j < getColumns(); j++) {
            double value = matrix[i][j];
            if (value != 0.0) {
                values.push_back(value);
                columnIndices.push_back(j);
                nonZeroElements++;
            }
        }
        rowPointers.push_back(nonZeroElements);
    }
    return *this;
}

void SparseMatrix::print(ostream &stream) {

    for (int i = 0; i < getRows(); i++) {
        for (int j = 0; j < getColumns(); j++) {
            int rowStart = rowPointers[i];
            int rowEnd = rowPointers[i + 1];

            bool found = false;
            for (int k = rowStart; k < rowEnd; k++) {
                if (columnIndices[k] == j) {
                    if (values[k] == 0){
                        values[k] = 0;
                    }
                    stream << values[k] << " ";
                    found = true;
                    break;
                }
            }

            if (!found) {
                stream << "0 ";
            }
        }
        stream << endl;
    }
}

SparseMatrix::~SparseMatrix() = default;

vector<vector<double>> SparseMatrix::getMatrix() {

    vector<vector<double>> result(getRows());

    for (int i = 0; i < getRows(); i++) {
        for (int j = 0; j < getColumns(); j++) {
            int rowStart = rowPointers[i];
            int rowEnd = rowPointers[i + 1];

            bool found = false;
            for (int k = rowStart; k < rowEnd; k++) {
                if (columnIndices[k] == j) {
                    result[i].push_back(values[k]);
                    found = true;
                    break;
                }
            }

            if (!found) {
                result[i].push_back(0);
            }
        }
    }

    return result;
}

void SparseMatrix::clear(){
    values.clear();
    columnIndices.clear();
    rowPointers.clear();
}