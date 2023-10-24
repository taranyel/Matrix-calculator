#include "GaussMethod.h"

/**
 * @brief Class to transpose matrix
 *
 * Is an inheritor of the class Operator.
 */
class Transposition : public Operator{

public:

    /**
     * @brief Construct a new Transposition object
     */
    Transposition();

    /**
     * @brief An override funtion to transpose matrix
     * 
     * Also function validates variables of the parent class according to all rules for matrix transposition.
     * 
     * @return Returns new Operand*. In case of error returns nullptr.
     */
    Operand* evaluate() override;
};

