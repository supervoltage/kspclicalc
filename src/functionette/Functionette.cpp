#include "Functionette.hpp"
#include <algorithm>

// constructors and destructors
Functionette::Functionette(std::string name, int min, int max, std::map<std::string, std::string> helper)
{}

// getters and setters
std::string Functionette::get_name() const              { return m_name; }
void Functionette::set_name(std::string new_name)       { m_name = new_name; }
std::pair<int, int> Functionette::get_bounds() const    { return m_arg_bounds; }

void Functionette::get_bounds(int& min, int& max) const
{
    min = m_arg_bounds.first;
    max = m_arg_bounds.second;
}

void Functionette::set_bounds(std::pair<int, int> new_bounds)
{
    m_arg_bounds.first = std::min(new_bounds.first, new_bounds.second);
    m_arg_bounds.second = std::max(new_bounds.first, new_bounds.second);
}

void Functionette::set_bounds(int min, int max)
{
    set_bounds(std::pair<int, int> {min, max} );
}

std::map<std::string, std::string> Functionette::get_helper() const
{
    return m_arg_helper;
}

void Functionette::set_helper(std::map<std::string, std::string> new_helper)
{
    m_arg_helper = new_helper;
}

void Functionette::insert_helper_pair(std::pair<std::string, std::string> pair)
{
    m_arg_helper[pair.first] = pair.second;
}

void Functionette::insert_helper_pair(std::string name, std::string desc)
{
    insert_helper_pair(std::pair<std::string, std::string> {name, desc} );
}

std::string Functionette::operator[] (std::string searchterm) // obtain argument value from one specific argument name
{
    // ?
}

std::vector<std::string> Functionette::get_args() const  // get all args; first is name, second is value
{
    return m_args;
}

void Functionette::store(std::string functionette)
{
    // ?
}
