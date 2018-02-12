#ifndef CLI_H
#define CLI_H

#include <vector>
#include <string>
#include <ostream>
#include "Command_DB.hpp"

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

// REWRITE WARNING
/*
 * I think I should completely rewrite the CLI parsing lib as I'm overcomplicating things again.
 * Standard GNU argument parsing doesn't take several positional arguments for a switch, it only
 * takes one. Therefore I have to write a more standard way of parsing arguments of the following
 * types:
 *      --longargname arg
 *      --longargname=arg
 *      -a
 *      -ab
 *      -abl arg
 * 
 * That means that the old way of parsing arguments for the internal DeltaV, ISP, TWR, FuelMass and
 * other calculators is not compliant with standard GNU. So I should rethink how that'll be parsed.
 * 
 * I could resort to my previous "functionette" idea in which the end user would write a "function"
 * into the commandline after the program name:
 *      kspclicalc dv(345, 5, 2.5)
 * 
 * The above would calculate the required information for DeltaV and spit it out. That also means
 * we can put multiple functionettes inside of each other:
 *      kspclicalc dv(345, 5, cpu(88.58))
 * which would calculate cpu() first, replace the third argument with the output, then calculate the
 * dv() functionette.
 * 
 * The functionette idea is still not compliant with GNU, but then again this program is not very
 * easy to write in a GNU compliant manner. It's not.. simple enough. It's not just a simple tool
 * like a calculator filled with buttons or simpler commands like "ls", "cd", "mv" etc.
*/

class CLI
{
private:
    std::string m_prog_name;
    bool m_verbose;
    Command_DB m_cmd_db;
    
public:
    CLI(std::vector<std::string> input);
    
    void load_input(std::vector<std::string> input);
    std::string get_prog_name();
    
    void set_verbose(bool);
    bool is_verbose();
    
    void register_command(Command& cmd);
    std::ostream& printCapabilities(std::ostream& os);
};

#endif
