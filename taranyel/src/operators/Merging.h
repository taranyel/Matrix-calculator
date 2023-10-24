#include "Multiplying.h"

/**
 * @brief Class to merge two matrices
 *
 * Is an inheritor of the class Operator.
 */
class Merging : public Operator{

public:

    /**
     * @brief Construct a new Merging object
     */
    Merging();

    /**
     * @brief An override funtion to merge two matrices
     * 
     * Also function validates variables of the parent class according to all rules for merging two matrices.
     * 
     * @return Returns a new Operand*. In case of error returns nullptr.
     */
    Operand *evaluate() override;
};
