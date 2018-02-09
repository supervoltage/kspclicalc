#ifndef COMMAND_DB
#define COMMAND_DB

/* Command_DB
 * 
 *  This class contains a searchable list of commands that are expected in the program's input.
 *  
 *  It serves to put down all the command definitions into one place where you can easily find
 *  the information and then call whatever functions or methods required.
 *  
 *  You can add more information to it whenever is required, albeit it's not expected to be altered
 *  much during runtime.
*/

#include <vector>
#include <string>
#include "Command.hpp"

class Searcher
{
public:
    virtual bool cmp(const Command&) = 0;
};

class Command_DB
{
private:
    std::vector<Command> m_db;
public:
    Command_DB();
    Command_DB(Command cmd);
    Command_DB(std::vector<Command> db);
    
    void reset_DB();
    void set_DB(std::vector<Command> db);
    void insert_Command(Command cmd);
    
    // Command search(std::string cmd_name);
    std::vector<Command> search(Searcher* srch);
    const std::vector<Command>& get_db();
};

#endif
