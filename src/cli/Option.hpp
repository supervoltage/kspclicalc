#ifndef OPTION_H
#define OPTION_H

/* This class defines what an argument is to a command
*/

#include <string>
#include <vector>

class Option
{
private:
    const std::string m_name;         //identifier for option
    const std::string m_desc;         //description of what this option is for
    const std::string m_short_name;   //short option name (aka single hyphen)
    const std::string m_long_name;    //long option name (aka double hyphen)
    const bool m_positional;
    const bool m_repeatable;      //indicates if option can exist several times in input
    
    std::string m_result;
    
public:
    Option(std::string name, std::string desc, std::string short_name, std::string long_name,
           bool positional, bool repeatable);
    Option(const Option& opt);
    std::string get_name() const;
    std::string get_desc() const;
    std::string get_short_name() const;
    std::string get_short_name_bare() const;
    std::string get_long_name() const;
    std::string get_long_name_bare() const;
    bool is_positional() const;
    bool is_repeatable() const;
    
    template <typename T>
    T get_result() const;
    
    void store(std::string arg);
    
    bool operator==(const Option& rhs) const;
};

#endif
