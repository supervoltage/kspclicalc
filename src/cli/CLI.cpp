#include "CLI.hpp"

CLI::CLI(std::vector<std::string> > input)
{
    load_input(input);
}

void CLI::load_input(std::vector<std::string> > input)
{
    // extract the program name
    m_prog_name = input[0];
    
    // loop through all elements of input vector apart from the first
        // if first char is a hyphen ( - )
            // extract that item and put it in a new vector
            // loop through the rest of the items, until either end of vector is met or an item starting with hyphen is found
                // if hyphen or end of vec is found: extract items and put them in the aforementioned new vector
                // modify input vector?
            // push this back into the main serparated_commands list
    
    // above steps are highly subject to change.
}

void CLI::get_prog_name()
{
    return m_prog_name;
}
