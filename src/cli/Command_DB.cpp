#include "Command_DB.hpp"
#include <algorithm>
#include <stdexcept>

Command_DB::Command_DB()
{}

Command_DB::Command_DB(Command cmd)
{
    insert_Command(cmd);
}

Command_DB::Command_DB(std::vector<Command> db)
{
    set_DB(db);
}

void Command_DB::reset_DB()
{
    m_db.clear();
}

void Command_DB::set_DB(std::vector<Command> db)
{
    m_db.clear();
    for (auto& it : db)
        m_db.push_back(it);
    
}

void Command_DB::insert_Command(Command cmd)
{
    m_db.push_back(cmd);
}

/*
Command Command_DB::search(std::string cmd_name)
{
    std::vector<Command>::const_iterator it;
    // can't use find() as we're looking for a Command object using a string. This search function
    // will need reworking.
    it = find(m_db.begin(), m_db.end(), cmd_name);
    
    if (it != m_db.end())
        return *it;
    else
        throw std::range_error("Command not found in database");
}
*/

std::vector<Command> Command_DB::search(Searcher* srch)
{
    std::vector<Command> out;
    for (const auto& it : m_db)
    {
        if (srch->cmp(it))
            out.push_back(it);
    }
    return out;
}
