#include "Operator.h"

/**
 * @brief Plus operator class
 *
 * Is an inheritor of the class Operator.
 */
class Plus : public Operator{
public:

    /**
     * @brief Construct a new Plus object
     */
    Plus();

    /**
     * @brief An override funtion to implement plus operator
     * 
     * Also function validates variables of the parent class according to all matrix sum rules.
     * 
     * @return Returns new Operand*. In case of error returns nullptr.
     */
    Operand* evaluate() override;
};

