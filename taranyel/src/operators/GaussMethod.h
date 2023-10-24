#include "Inversion.h"

/**
 * @brief Class to find the triangular shape of a matrix
 * 
 * To find the triangular shape of the matrix, class uses the Gauss method.
 * Is an inheritor of the class Operator.
 */
class GaussMethod : public Operator{

public:

    /**
     * @brief Construct a new Gauss Method object
     */
    GaussMethod();

    /**
     * @brief An override funtion to find the triangular shape of a matrix
     * 
     * Also function validates variables of the parent class according to all rules for finding the triangular shape of the matrix.
     * 
     * @return Returns new Operand*. In case of error returns nullptr.
     */
    Operand* evaluate() override;

    /**
     * @brief Helper function to find the triangular shape of a matrix.
     * 
     * @param matrix 
     * @return vector<vector<double>> (matrix)
     */
    vector<vector<double>> gaussMethod(vector<vector<double>> matrix);
};

