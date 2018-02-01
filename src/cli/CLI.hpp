#ifndef CLI_H
#define CLI_H

#include <vector>
#include <string>

// In essence this class does the below:
/*  - Read input, detect program name and extract it
 *  - Read for commands to execute (LOOP):
 *      - find arguments beginning with character "-" and check it against the Command_Database for matches (LOOP):
 *          - If a match is found:
 *              - Create a Command object of the command's nature (for e.g. for "-dv" input, create a Command_DeltaV object (?)
 *              - Insert the arguments for it until another "-" character is met at the beginning of the next argument (LOOP) (1)
 *              - Insert newly built Command into the Executable_Command_List
 *              - Modify input vector to take out the command name and its arguments
 *          - If no match is found, return peacefully
 *  - If exec() is called, call all saved commands in the executable command list with their
 *  callback functions.
 * 
 * (?) I don't believe this is the right approach. There must be a better way...
 * 
 * (1) Exception to be thrown if:
 *      - Minimum number of arguments is not reached
 *      - Maximum number of arguments is exceeded
 *      - Unexpected input is present (NaN, unusual symbols etc).
*/

class CLI
{
private:
    std::string m_prog_name;
    bool m_verbose;
    
public:
    CLI(std::vector<std::string> input);
    
    void load_input(std::vector<std::string> input);
    std::string get_prog_name();
    
    void set_verbose(bool);
    bool is_verbose();
};

#endif
