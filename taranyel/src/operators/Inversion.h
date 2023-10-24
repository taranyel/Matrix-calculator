#include "Determinant.h"

/**
 * @brief Class to find matrix inversion
 * 
 * Is an inheritor of the class Determinant because uses its calculateDeterminant() and subMatrxi() functions.
 */
class Inversion : public Determinant{

public:

    /**
     * @brief Construct a new Inversion object
     */
    Inversion();

    /**
     * @brief An override funtion to find the inversion of a matrix
     * 
     * Also function validates variables of the parent class according to all rules for finding the inversion of the matrix.
     * 
     * @return Returns new Operand*. In case of error returns nullptr.
     */
    Operand* evaluate() override;

    /**
     * @brief Helper function to get the cofactor of the origin matrix
     * 
     * @param matrix is the origin matrix
     * @return vector<std::vector<double>> (cofactor matrix).
     */
    vector<std::vector<double>> getCofactor(const std::vector<std::vector<double>>& matrix);
};

