#include "Functionette.hpp"
#include <stdexcept>
#include <cctype>

// constructors and destructors
Functionette::Functionette()
{}

Functionette::Functionette(std::string name, std::vector<std::string> args)
    : m_name(name), m_args(args)
{}

Functionette::Functionette(std::string functionette_string)
{
    parse(functionette_string);
}
    
// getters and setters
std::string Functionette::get_name() const              { return m_name; }
void Functionette::set_name(std::string new_name)       { m_name = new_name; }

std::string Functionette::operator[] (int arg_num) // obtain argument value from one specific argument name
{
    return m_args[arg_num];
}

std::vector<std::string> Functionette::get_args() const  // get all args; first is name, second is value
{
    return m_args;
}

void Functionette::parse(std::string functionette)
{
    // input: example(arg1, arg2, arg3)
    
    const std::string::size_type size = functionette.size();
    std::string::size_type j = 0;
    std::string::size_type i = 0;
    
    if (isdigit(functionette[0]))
        throw std::invalid_argument("incorrect functionette name \'" + functionette + "\'; name begins with a digit");
    
    while (i < size)
    {
        if (functionette[i] == '(')
        {
            m_name = functionette.substr(j, i);
            j = i;
        }
        if (functionette[i] == ',')
        {
            m_args.push_back(functionette.substr(j+1, i));
            j = i;
        }
        
        ++i;
    }
}
