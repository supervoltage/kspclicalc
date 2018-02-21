#include "Option.hpp"
#include <cstdlib>
#include <string>
#include <algorithm>

Option::Option(std::string name, std::string desc, std::string short_name, std::string long_name,
               bool positional, bool repeatable, bool negator)
    : m_name(name), m_desc(desc), m_short_name(short_name), m_long_name(long_name),
      m_positional(positional), m_repeatable(repeatable), m_negator(negator)
{}

Option::Option(const Option& opt)
    : m_name(opt.m_name), m_desc(opt.m_desc), m_short_name(opt.m_short_name), m_long_name(opt.m_long_name),
      m_positional(opt.m_positional), m_repeatable(opt.m_repeatable), m_negator(opt.m_negator), m_result(opt.m_result)
{}

std::string Option::get_name() const { return m_name; }
std::string Option::get_desc() const { return m_desc; }
std::string Option::get_short_name() const { return "-" + m_short_name; }
std::string Option::get_short_name_bare() const { return m_short_name; }
std::string Option::get_long_name() const  { return "--" + m_long_name; }
std::string Option::get_long_name_bare() const { return m_long_name; }
bool Option::is_positional() const { return m_positional; }
bool Option::is_repeatable() const { return m_repeatable; }
bool Option::is_negator() const { return m_negator; }

template <typename T>
T Option::get_result() const
{
    return m_result;
}

template<>
std::string Option::get_result<std::string>() const { return m_result; }
template<>
int Option::get_result<int>() const                 { return atoi(m_result.c_str()); }
template<>
double Option::get_result<double>() const           { return atof(m_result.c_str()); }
void Option::store(std::string arg)                 { m_result = arg; }

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

bool Option::operator==(const Option& rhs) const
{
    if (m_name == rhs.m_name /* &&
        m_short_name == rhs.m_short_name &&
        m_long_name == rhs.m_long_name &&
        m_positional == rhs.m_positional &&
        m_repeatable == rhs.m_repeatable */ )
        return true;
    else
        return false;
}
