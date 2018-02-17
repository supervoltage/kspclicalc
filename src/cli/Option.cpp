#include "Option.hpp"
#include <cstdlib>
#include <string>
#include <algorithm>

Option::Option(std::string name, std::string short_name, std::string long_name, bool positional, bool repeatable)
    : m_name(name), m_short_name(short_name), m_long_name(long_name), m_positional(positional), m_repeatable(repeatable)
{}

Option::Option(const Option& opt)
    : m_name(opt.m_name), m_short_name(opt.m_short_name), m_long_name(opt.m_long_name),
      m_positional(opt.m_positional), m_repeatable(opt.m_repeatable), m_result(opt.m_result)
{}

std::string Option::get_name() const { return m_name; }
std::string Option::get_short_name() const { return "-" + m_short_name; }
std::string Option::get_short_name_bare() const { return m_short_name; }
std::string Option::get_long_name() const  { return "--" + m_long_name; }
std::string Option::get_long_name_bare() const { return m_long_name; }
bool Option::is_positional() const { return m_positional; }
bool Option::is_repeatable() const { return m_repeatable; }

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
    std::string str = m_result;
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    
    if (str == "true" || str == "yes" || str == "y" || str == "1")
        return true;
    else
        return false;
}
