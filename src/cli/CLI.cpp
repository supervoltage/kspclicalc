#include "CLI.hpp"

CLI::CLI(std::vector<std::string> input)
{
    load_input(input);
}

void CLI::load_input(std::vector<std::string> input)
{
    // extract the program name
    m_prog_name = input[0];
    if (m_prog_name[0] == '.' && m_prog_name[1] == '/')
        m_prog_name.erase(0,2);
    
    // loop through all elements of input vector apart from the first
        // if first char is a hyphen ( - )
            // extract that item and put it in a new vector
            // loop through the rest of the items, until either end of vector is met or an item starting with hyphen is found
                // if hyphen or end of vec is found: extract items and put them in the aforementioned new vector
                // modify input vector?
            // push this back into the main serparated_commands list
    
    // above steps are highly subject to change.
}

std::string CLI::get_prog_name()
{
    return m_prog_name;
}

void CLI::set_verbose(bool)
{
    m_verbose = true;
}

bool CLI::is_verbose()
{
    return m_verbose;
}

void CLI::register_command(Command& cmd)
{
    m_cmd_db.insert_Command(cmd);
}

std::ostream& CLI::printCapabilities(std::ostream& os)
{
    // more things to be added here later
    for (auto& it : m_cmd_db.get_db())
    {
        it.printHelp(os, false);
    }
    return os;
}
