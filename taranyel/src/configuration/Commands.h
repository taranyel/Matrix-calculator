#include <iomanip>
#include <map>

using namespace std;

/**
 * @brief Command storage class
 */
class Commands {
public:

    /**
     * @brief Destroy the Commands object
     */
    virtual ~Commands();
    
    map<string, int> commands; ///map contains commands from config file.
};