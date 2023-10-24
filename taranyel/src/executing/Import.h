#include "Export.h"
#include <fstream>

/**
 * @brief Import class
 */
class Import {

public:

    /**
     * @brief Construct a new Import object
     * 
     * @param fileName 
     * @param varName may be nullptr
     */
    Import(const string &fileName, const string &varName);

    /**
     * @brief Create a new matrix
     * 
     * This class uses functions from the class Evaluate, because the import file contents the whole expressions.
     * And as a result of the calculation, a vector<vector<double>> is returned from which is nessseesary to make a new matrix
     * 
     * @param zeroNumber 
     * @param values 
     * @param matrix 
     * @return Returns new matrix 
     */
    Matrix *createMatrix(int zeroNumber, int values, vector<vector<double>> matrix);

    /**
     * @brief Function to import data from a file
     * 
     * @return Returns a new map with imported operands. Map contains Operand object and its name.
     *  In case of error returns an empty map.
     */
    map<string, Operand*> import();

    /**
     * @brief Function to import one operand from a file
     * 
     * @return Returns imported operand.
     */
    Operand* importOne();

    /**
     * @brief Function to import all operands from a file
     * 
     * @return Returns a new map with imported operands. Map contains Operand object and its name.
     *  In case of error returns an empty map.
     */
    map<string, Operand*> importAll();

    string fileName{};
    string varName{};
};

