#include "Matrix.h"
#include <iostream>

using namespace std;

/**
 * @brief Class represented a number
 * 
 *Is an inheritor of the class Operand.
 */
class Number : public Operand{
public:

    /**
     * @brief Construct a new Number object
     * 
     * @param value 
     */
    Number(double value);

    /**
     * @brief Construct a new Number object
     */
    Number();

    /**
     * @brief Destroy the Number object
     */
    ~Number() override;

    /**
     * @brief Function to print a number
     * 
     * @param stream is an output stream
     */
    void print(ostream &stream) override;

    /**
     * @brief Function to clear a number
     * 
     */
    void clear() override;

    /**
     * @brief Get the type of operand
     * 
     * @return Returns NUMBER type 
     */
    int getType() override;

    /**
     * @brief Get the number
     * 
     * @return pair<double, vector<vector<double>>> (fills only first field)
     */
    pair<double, vector<vector<double>>> getValue() override;

    double value{};
};
