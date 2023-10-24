#include "Trimming.h"

/**
 * @brief Class to find matrix rank
 *
 * Is an inheritor of the class GaussMethod, because to find the rank of a matrix, 
 * it is necessary to reduce it to a triangular form using functions from GaussMethod class.
 */
class Rank : public GaussMethod{

public:

    /**
     * @brief Construct a new Rank object
     */
    Rank();

    /**
     * @brief An override funtion to find matrix rank
     * 
     * Also function validates variables of the parent class according to all rules for finding matrix rank.
     * 
     * @return Returns new Operand*. In case of error returns nullptr.
     */
    Operand* evaluate() override;
};
