#ifndef COMMAND_H
#define COMMAND_H

/* Command
 * 
 *  This class merely holds information and is used by Command_DB to hold a list of the
 *  various commands expected in the input.
 * 
 *  The CLI object will marry the Command_Database with whatever callback functions or methods 
 *  the user may provide.
 * 
 *  A command has a name, minimum and maximum argument expected argument counts and a list
 *  containing a list of what the arguments are, in the right order with a description. 
 * 
 *  All of the above parameters should really be const. We don't expect to be changing this
 *  information during runtime.
*/

#include <string>
#include <vector>
#include <utility>

// first string is the argument's name, the second is its description
typedef std::pair<std::string, std::string> argument;

class Command
{
private:
    const std::string m_cmd;
    const unsigned int m_min_arg_count;
    const unsigned int m_max_arg_count;
    const std::vector<argument> m_arg_list;
public:
    Command(std::string cmd, unsigned int min_arg_count, unsigned int max_arg_count,
            std::vector<argument> arg_list);
    std::string get_scmd() const;
    const unsigned int get_min_arg_count() const;
    const unsigned int get_max_arg_count() const;
    const std::vector<argument> get_arg_list() const;
};

#endif
