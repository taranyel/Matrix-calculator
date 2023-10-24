#include <vector>
#include "DenseMatrix.h"

/**
 * @brief Class represented a sparse matrix
 * 
 * Is an inheritor of the class Matrix.
 */
class SparseMatrix : public Matrix {
public:

    /**
     * @brief Construct a new Sparse Matrix object
     * 
     * @param rows 
     * @param columns 
     */
    SparseMatrix(int rows, int columns);

    /**
     * @brief Destroy the Sparse Matrix object
     */
    ~SparseMatrix() override;

    /**
     * @brief Function to print a sparse matrix
     * 
     * @param stream is an output stream
     */
    void print(ostream &stream) override;

    /**
     * @brief Get the sparse matrix represented by vector<vector<double>>
     * 
     * @return vector<vector<double>> (matrix)
     */
    vector<vector<double>> getMatrix() override;

    /**
     * @brief Create a Sparse Matrix with CSR
     * 
     * CSR, or Compressed Sparse Row, is a popular format for representing sparse matrices. 
     * It is an efficient way to store and manipulate matrices that contain a large number of zero elements. 
     * The CSR format is based on three arrays:
     * 1. Values array: This array contains the non-zero values of the sparse matrix, stored row by row. 
     * The values are typically stored in a one-dimensional array.
     * 2. Column Indices array: This array stores the column index for each corresponding non-zero value in the values array. 
     * The column indices are also stored row by row.
     * 3. Row pointers array: This array indicates the starting position of each row in the values and column indices arrays. 
     * It stores the cumulative count of non-zero elements up to each row.
     * 
     * @param matrix 
     * @return SparseMatrix object
     */
    SparseMatrix createSparseMatrixCSR(const vector<vector<double>> &matrix);

    /**
     * @brief Function to clear a sparse matrix
     */
    void clear() override;

    vector<double> values; ///values array
    vector<int> columnIndices; ///column indices array
    vector<int> rowPointers; ///row pointers array
};