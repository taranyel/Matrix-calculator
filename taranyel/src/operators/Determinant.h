#include "Merging.h"

/**
 * @brief Class to calculate matrix determinant
 * 
 * Is an inheritor of the class Operator.
 */
class Determinant : public Operator{
public:

    /**
     * @brief Construct a new Determinant object
     */
    Determinant();

    /**
     * @brief An override funtion to calculate matrix determinant
     * 
     * Also function validates variables of the parent class according to all rules for finding the determinant.
     * 
     * @return Returns a new Operand*. In case of error returns nullptr.
     */
    Operand* evaluate() override;

    /**
     * @brief Helper function to calculate matrix determinant
     * 
     * @param matrix 
     * @return Returns value of determinant (double) 
     */
    double calculateDeterminant(const vector<vector<double>>& matrix);

    /**
     * @brief Helper function to find a submatrix of the original matrix
     * 
     * @param matrix is an original matrix
     * @param row is the index of the row to be removed from the matrix.
     * @param col is the index of the column to be removed from the matrix.
     * @return vector<vector<double>> (The submatrix obtained by removing the specified row and column).
     */
    vector<vector<double>> subMatrix( vector<vector<double>> matrix, int row, int col);
};

