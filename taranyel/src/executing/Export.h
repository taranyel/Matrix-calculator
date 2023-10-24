#include "Evaluate.h"
#include <fstream>

/**
 * @brief Export class
 */
class Export {
public:

    /**
     * @brief Construct a new Export object
     * 
     * @param fileName 
     * @param varName may be nullptr
     */
    Export(const string &fileName, const string &varName);

    /**
     * @brief Function to export data to a given file
     * 
     * @param operands 
     * @return Returns true if export was successful.
     */
    bool exportOperands(const map<string, Operand*>& operands);

    /**
     * @brief Function to export all operands to a file
     * 
     * @param operands 
     * @return Returns true if export was successful.
     */
    bool exportAll(const map<string, Operand*>& operands);

    /**
     * @brief Function to export one operand to a file
     * 
     * @param operands 
     * @return Returns true if export was successful.
     */
    bool exportOne(const map<string, Operand*>& operands);

    string fileName{};
    string varName{};
};
