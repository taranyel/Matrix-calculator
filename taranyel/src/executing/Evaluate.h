#include "ReadOperand.h"
#include "Operators.h"
#include <map>
#include <stack>

/**
 * @brief Class for handling expressions
 * 
 * Is an inheritor of the class Operators.
 */
class Evaluate : public Operators{
public:

    /**
     * @brief Construct a new Evaluate object
     */
    Evaluate();

    /**
     * @brief Function to evaluate given expression
     * 
     * @param operands operand map
     * @param operators operator map
     * @param iss stream represented expression
     * @return New Operand* or nullptr in case of error. 
     */
    Operand* evaluate(map<string, Operand*> operands, map<string, Operator*> operators, istringstream& iss);

    /**
     * @brief Create a new matrix
     * 
     * @param zeroNumber 
     * @param values 
     * @param matrix 
     * @return New Matrix* 
     */
    Matrix *createMatrix(int zeroNumber, int values, vector<vector<double>> matrix);

    void clearVectors(vector<Operand*> garbage, vector<Operand*> variables, vector<Operand*> stack);
};

