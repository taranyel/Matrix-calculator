#include "Plus.h"

/**
 * @brief Minus operator class
 *
 * Is an inheritor of the class Operator.
 */
class Minus : public Operator{
public:

    /**
     * @brief Construct a new Minus object
     */
    Minus();

    /**
     * @brief An override funtion to implement minus operator
     * 
     * Also function validates variables of the parent class according to all substraction rules.
     * 
     * @return Returns new Operand*. In case of error returns nullptr.
     */
    Operand* evaluate() override;
};


