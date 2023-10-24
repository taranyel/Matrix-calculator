#include "Minus.h"

/**
 * @brief Class for multiplying two operands
 *
 * Is an inheritor of the class Operator.
 */
class Multiplying : public Operator{

public:

    /**
     * @brief Construct a new Multiplying object
     */
    Multiplying();

    /**
     * @brief An override funtion to implement multiplication operator
     * 
     * Also function validates variables of the parent class according to all multiplication rules.
     * 
     * @return Returns new Operand*. In case of error returns nullptr.
     */
    Operand* evaluate() override;

    /**
     * @brief Function to implement multiplication between number and matrix
     * 
     * @param number 
     * @param matrix 
     * @return vector<vector<double>> (matrix)
     */
    vector<vector<double>> numberMulMatrix(double number, vector<vector<double>> matrix);


    /**
     * @brief Function to implement multiplication between two matrices
     * 
     * @param matrix1 
     * @param matrix2 
     * @return vector<vector<double>> (matrix)
     */
    vector<vector<double>> matrixMulMatrix (vector<vector<double>> matrix1, vector<vector<double>> matrix2);
};

