#include "Matrix.h"

Matrix::Matrix(int rows, int columns) : rows(rows), columns(columns) {}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getColumns() const {
    return columns;
}

int Matrix::getType() {
    return MATRIX;
}

pair<double, vector<vector<double>>> Matrix::getValue() {
    pair<double, vector<vector<double>>> value (0, getMatrix());
    return value;
}

Matrix::Matrix() = default;
