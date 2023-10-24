#include "Operator.h"

Operator::Operator() = default;

Operator::~Operator() {
    variables.clear();
}

void Operator::clearMatrix(vector<vector<double>> matrix) {
    for (auto &i: matrix) {
        i.clear();
    }
    matrix.clear();
}

void Operator::setVariables(vector<Operand *> newVariables) {
    this->variables.clear();
    this->variables = newVariables;
}

Matrix *Operator::createMatrix(vector<vector<double>> matrix) {
    Matrix* result;
    if (zeroNumber > values) {
        SparseMatrix *sparseMatrix = new SparseMatrix((int) matrix.size(), (int) matrix[0].size());
        sparseMatrix->createSparseMatrixCSR(matrix);
        result = sparseMatrix;
    } else {
        result = new DenseMatrix((int) matrix.size(), (int) matrix[0].size(), matrix);
    }

    return result;
}


