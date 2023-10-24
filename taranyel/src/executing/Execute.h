#define SCAN 0
#define PRINT 1
#define IMPORT 2
#define EXPORT 3
#define EQUAL 4
#define DELETE 5
#define EXIT 6
#define HELP 20

#include "../error/Error.h"
#include "Import.h"
#include <iostream>
#include <map>
#include <vector>
#include <cctype>

using namespace std;

/**
 * @brief Class that controls the program
 * 
 * A class that directs the actions of the program depending on the command entered.
 */
class Execute {
public:

    /**
     * @brief Construct a new Execute object
     * 
     * @param expression 
     * @param command 
     */
    Execute(const string &expression, int command);

    /**
     * @brief Destroy the Execute object
     */
    ~Execute();

    /**
     * @brief Set the expression
     * 
     * @param newExpression 
     */
    void setExpression(const string &newExpression);

    /**
     * @brief Set the command
     * 
     * @param newCommand 
     */
    void setCommand(int newCommand);

    /**
     * @brief Command processing function
     * 
     * @return Returns either 0 on success, EXIT or error code.
     */
    int evaluate();

    /**
     * @brief Function to handle expression
     * 
     * @param name is the name of the new operand
     * @return Returns true in case of successful evaluation.
     */
    bool evaluateExpr(const string &name);

    /**
     * @brief Function to add new Operand to the operand map
     * 
     * @param name 
     * @param operand 
     */
    void add(const string &name, Operand *operand);

    /**
     * @brief Function to scan new operand from standart input
     * 
     * @param name is the name of the new operand
     * @return Returns 0 on success or error code. 
     */
    int scan(const string &name);

    /**
     * @brief Function to print operand
     * 
     * @param name is the name of the operand
     */
    void print(const string &name);

    /**
     * @brief Function to delete variable from the operand map
     * 
     * @param name is the name of the operand
     */
    void deleteVar(const string &name);

    /**
     * @brief Function to exit the program
     * 
     */
    void exit();

    /**
     * @brief Function to import data from a file
     * 
     * @param fileName 
     * @param varName is nullptr if user wants to import all data from a file
     * @return Returns true if import was successful. 
     */
    bool import(const string& fileName, const string& varName);

    /**
     * @brief Function to export data to a file
     * 
     * @param fileName 
     * @param varName is nullptr if user wants to export all data to a file
     * @param operandsExp map with all operands
     * @return Returns true if export was successful.
     */
    bool exportOperands(const string& fileName, const string& varName, const map<string, Operand*>& operandsExp);

    /**
     * @brief Function to print all operators
     */
    void printAllOperators();

    /**
     * @brief Function to check if the operand is not present in the operand map
     * 
     * @param name 
     * @return Returns true if the operand is not present in the operands map.
     */
    bool checkName(const string& name);

    Evaluate newEvaluate;
    map<string, Operand *> operands;
    string expression;
    int command;
};