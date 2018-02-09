#include "Command.hpp"
#include <stdexcept>

Command::Command(std::string cmd, std::string desc, unsigned int min_arg_count,
                 unsigned int max_arg_count, std::vector<argument> arg_list)
    : m_cmd(cmd), m_desc(desc), m_min_arg_count(min_arg_count), m_max_arg_count(max_arg_count),
      m_arg_list(arg_list)
{}

std::string Command::get_cmd() const
{
    return m_cmd;
}

std::string Command::get_desc() const
{
    return m_desc;
}

const unsigned int Command::get_min_arg_count() const
{
    return m_min_arg_count;
}

const unsigned int Command::get_max_arg_count() const
{
    return m_max_arg_count;
}

const std::vector<argument> Command::get_arg_list() const
{
    return m_arg_list;
}

std::ostream& Command::printHelp(std::ostream& os, bool detail) const
{
    // print out line of format: command_name [arg1] [arg2] [arg3]...
    os << "Syntax: " << m_cmd;
    for (auto& it : m_arg_list)
    {
        os << " [" << it.first << "]";
    }
    os << "\n" << "Description: " << m_desc << "\n";
    
    // print several lines of below format and example output:
    /* Description of arguments:
     *     [arg1]   [desc1]
     *     [arg2]   [desc2]
     * ...
    */
    
    if (detail)
    {
        os << "Description of arguments:\n";
        for (auto& it : m_arg_list)
        {
            os << "\t" << it.first << "\t" << it.second << "\n";
        }
    }
    return os;
}
