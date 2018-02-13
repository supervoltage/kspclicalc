#include "Option.hpp"
#include <cstdlib>

Option::Option(std::string short_name, std::string long_name)
{
    if (short_name[0] != '-')
    {
        short_name.insert(0,"-");
        m_short_name = short_name;
    }
    else
        m_short_name = short_name;
    if (long_name[0] != '-' && long_name[1] != '-')
    {
        long_name.insert(0,"--");
        m_long_name = long_name;
    }
    else
        m_long_name = long_name;
}

std::string Option::get_short_name() const { return m_short_name; }
std::string Option::get_long_name() const  { return m_long_name; }

template <typename T>
T Option::get_result() const
{
    return m_result;
}

template<>
std::string Option::get_result<std::string>() const     { return m_result; }

template<>
int Option::get_result<int>() const             { return atoi(m_result.c_str()); }

template<>
double Option::get_result<double>() const          { return atof(m_result.c_str()); }

void Option::store(std::string arg)        { m_result = arg; }

template<>
bool Option::get_result<bool>() const
{
    char ch = m_result[0];
    switch (ch)
    {
        case 'y': return true;
        case 'Y': return true;
        case 't': return true;
        case 'T': return true;
        case '1': return true;
        
        case 'n': return false;
        case 'N': return false;
        case 'f': return false;
        case 'F': return false;
        case '0': return false;
        default: return false;
    }
}
