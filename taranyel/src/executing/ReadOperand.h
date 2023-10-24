#include <vector>
#include <iostream>

using namespace std;

/**
 * @brief Operand reading class
 */
class ReadOperand {
public:

    /**
     * @brief Construct a new Read Operand object
     */
    ReadOperand();

    /**
     * @brief Static function to read a matrix
     * 
     * @param buffer
     * @param zeroNumber is used for creating a new Matrix object
     * @param values is used for creating a new matrix
     * @return Returns a vector<vector<double>> on success or an empty vector in case of error.
     */
    static vector<vector<double>> readMatrix(string buffer, int *zeroNumber, int *values);

    /**
     * @brief Static function to clear matrix
     * 
     * @param matrix 
     */
    static void clearMatrix(vector<vector<double>> matrix);

    /**
     * @brief Static function to read a number
     * 
     * @param buffer 
     * @param value is used for creating new Number object
     * @return Returns true on success reading a number
     */
    static bool readNumber(const string& buffer, double *value);
};

