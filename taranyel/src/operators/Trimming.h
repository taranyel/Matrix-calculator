#include "Transposition.h"

/**
 * @brief Class to trim matrix
 *
 * Is an inheritor of the class Operator.
 */
class Trimming : public Operator{

public:

    /**
     * @brief Construct a new Trimming object
     */
    Trimming();

    /**
     * @brief An override funtion to trim matrix
     * 
     * Also function validates variables of the parent class according to all rules for matrix trimming.
     * 
     * @return Returns new Operand*. In case of error returns nullptr.
     */
    Operand* evaluate() override;
};
