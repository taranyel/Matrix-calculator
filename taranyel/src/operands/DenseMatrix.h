#include <vector>
#include <iostream>
#include <algorithm>
#include "Number.h"

using namespace std;

/**
 * @brief Class represented a dense matrix
 * 
 * Is an inheritor of the class Matrix.
 */
class DenseMatrix : public Matrix {
public:

    /**
     * @brief Construct a new Dense Matrix object
     * 
     * @param rows 
     * @param columns 
     * @param matrix 
     */
    DenseMatrix(int rows, int columns, const vector<vector<double>> &matrix);

    /**
     * @brief Function to clear denseMatrix
     */
    void clear() override;

    /**
     * @brief Destroy the Dense Matrix object
     */
    ~DenseMatrix() override;

    /**
     * @brief Function to print a dense matrix
     * 
     * @param stream is an output stream
     */
    void print(ostream &stream) override;

    /**
     * @brief Get the dense matrix represented by vector<vector<double>>
     * 
     * @return vector<vector<double>> (matrix)
     */
    vector<vector<double>> getMatrix() override;

    vector<vector<double>> matrix;
};