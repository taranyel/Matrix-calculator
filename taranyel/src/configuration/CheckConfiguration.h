#include <iostream>
#include <sstream>
#include "Commands.h"

using namespace std;

/**
 * @brief Configuration class
 * 
 * This class is responsible for the configuration file.
 * Is an inheritor of the class Commands.
 */
class CheckConfiguration : public Commands{
public:

     /**
     * @brief Function to check configuration
     * 
     * The function checks if everything is fine with the config file and if the command map was completed successfully.
     * 
     * @param fileName 
     * @return Returns true if congiguration file is okay.
     */
    bool checkConfig(const string &fileName);

    /**
     * @brief Function to fill configuration map
     * 
     * @param fileName 
     * @return Returns true if map filling passed without errors.
     */
    bool fillConfig(const string& fileName);

    /**
     * @brief Function to validate file context
     * 
     * @param str 
     * @return Returns true if the validation was successful.
     */
    bool validate (const string& str);

    /**
     * @brief Create a new configuration file and fill it
     * 
     * @param fileName 
     */
    void createConfig(const char *fileName);
};