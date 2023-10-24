#include <iostream>
#include "../configuration/CheckConfiguration.h"
#include "../executing/Execute.h"

using namespace std;

/**
 * @brief Standart input parsing class
 * 
 * Class that reads standart input, validates it, and passes the entered command to the class Execute.
 * Is an inheritor of the class Commands.
 */
class Input : public Commands {
public:

    /**
     * @brief Construct a new Input object
     * 
     * @param configuration 
     */
    explicit Input(const Commands& configuration);

    /**
     * @brief Reading input function
     * 
     * @return Returns true on successful reading. 
     */
    bool readInput();

    /**
     * @brief Function to validate entered data
     * 
     * @return Returns 0 on success or returns an error code 
     */
    int checkInput();

    /**
     * @brief Function to print all user commands 
     */
    void printAllCommands();

    string buffer;
    int command;
};