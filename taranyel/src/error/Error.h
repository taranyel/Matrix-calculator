#include <iostream>
#define UNKNOWN_COMMAND 9
#define VAR_DOES_NOT_EXIST 7
#define VAR_ALREADY_EXISTS 8
#define INVALID_INPUT 10
#define INVALID_EXPRESSION 11
#define INVALID_COMMAND_ORDER 16
#define INCOMPLETE_COMMAND 17
#define TOO_MUCH_VARIABLES_ENTERED 18
#define INVALID_NAME 19
#define UNSUCCESSFUL_IMPORT 21
#define UNSUCCESSFUL_EXPORT 22

/**
 * @brief Error output class
 */
class Error {
public:

    /**
     * @brief Function to print error.
     * 
     * @param errorCode 
     */
    static void printError(int errorCode);
};


