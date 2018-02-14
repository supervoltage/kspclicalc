#ifndef OPTION_H
#define OPTION_H

/* This class defines what an argument is to a command
*/

#include <string>
#include <vector>

class Option
{
private:
    std::string m_short_name;   //short option name (aka single hyphen)
    std::string m_long_name;    //long option name (aka double hyphen)
    std::string m_result;
    const bool m_positional;
    const bool m_repeatable;      //indicates if option can exist several times in input
public:
    Option(std::string short_name, std::string long_name, bool positional, bool repeatable);
    std::string get_short_name() const;
    std::string get_long_name() const;
    bool is_positional() const;
    bool is_repeatable() const;
    
    template <typename T>
    T get_result() const;
    
    void store(std::string arg);
};

#endif
