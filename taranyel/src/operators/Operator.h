#include "../operands/SparseMatrix.h"
#include <vector>

/**
 * @brief An abstract class represents operatop
 */
class Operator {

public:

    /**
     * @brief Construct a new Operator object
     */
    Operator();

    /**
     * @brief Destroy the Operator object
     */
    virtual ~Operator();

    /**
     * @brief A virtual funtion to implement operator
     * 
     * Also function validates variables of the Operator class.
     * 
     * @return Returns new Operand*. In case of error returns nullptr.
     */
    virtual Operand* evaluate() = 0;

    /**
     * @brief Set the Operator variables
     * 
     * @param newVariables 
     */
    void setVariables(vector<Operand*> newVariables);

    /**
     * @brief Function to clear matrix
     * 
     * @param operand 
     */
    void clearMatrix(vector<vector<double>> operand);

    /**
     * @brief Create a Matrix object
     * 
     * @param matrix 
     * @return Matrix* 
     */
    Matrix* createMatrix (vector<vector<double>> matrix);

protected:
    int zeroNumber;
    int values;
    vector<Operand *> variables;
};
