#include "Operand.h"
#include <iomanip>
#include <vector>

using namespace std;

/**
 * @brief An abstract class represented matrix
 * 
 * Is an inheritor of the class Operand.
 */
class Matrix : public Operand {
private:
    int rows{};
    int columns{};

public:

    /**
     * @brief Construct a new Matrix object (empty)
     */
    Matrix();

    /**
     * @brief Construct a new Matrix object
     * 
     * @param rows 
     * @param columns 
     */
    Matrix(int rows, int columns);

    /**
     * @brief Destroy the Matrix object
     */
    ~Matrix() override = default;

    /**
     * @brief Get the rows
     * 
     * @return Returns amount of rows .
     */
    int getRows() const;

    /**
     * @brief Get the columns
     * 
     * @return Returns amount of columns. 
     */
    int getColumns() const;

    /**
     * @brief Function to print a matrix
     * 
     * @param stream is an output stream
     */
    void print(ostream &stream) override = 0;

    /**
     * @brief Function to clear a matrix
     */
    void clear() override = 0;

    /**
     * @brief Get the type of operand
     * 
     * @return Returns a MATRIX type 
     */
    int getType() override;

    /**
     * @brief Get the Value (matrix or number)
     * 
     * @return pair<double, vector<vector<double>>> (fills only second field)
     */
    pair<double, vector<vector<double>>> getValue() override;

    /**
     * @brief Get the matrix
     * 
     * @return vector<vector<double>> (matrix)
     */
    virtual vector<vector<double>> getMatrix() = 0;
};