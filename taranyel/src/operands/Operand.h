#include <vector>
#include <iostream>
#include <sstream>

#define MATRIX 13
#define NUMBER 14

using namespace std;

/**
 * @brief An abstract class represented an operand
 */
class Operand {

public:

    /**
     * @brief Destroy the Operand object
     */
    virtual ~Operand();

    /**
     * @brief Virtual function to print an operand
     * 
     * @param stream is an output stream
     */
    virtual void print(ostream &stream) = 0;

    /**
     * @brief Virtual function to clear an operand
     */
    virtual void clear() = 0;

    /**
     * @brief Get the type of an operand
     * 
     * @return Returns an operand type (int) 
     */
    virtual int getType() = 0;

    /**
     * @brief Get the value of an operand
     * 
     * @return pair<double, vector<vector<double>>>
     */
    virtual pair<double, vector<vector<double>>> getValue() = 0;
};