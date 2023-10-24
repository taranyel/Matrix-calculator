#include <map>
#include <iostream>
#include "../operators/Rank.h"

using namespace std;

/**
 * @brief Operator storage class
 * 
 */
class Operators {
public:

    /**
     * @brief Function to fill operator map
     */
    void fillOperators();

    /**
     * @brief Destroy the Operators object
     */
    virtual ~Operators();

    map<string, Operator*> operators;
};