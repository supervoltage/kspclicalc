#include "Functionette.hpp"
#include <stdexcept>
#include <cctype>

// for debugging, to be removed later
#include <iostream>

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

void Functionette::parse(std::string func)
{
    if (func.size() == 0)
        throw std::invalid_argument("missing input, expected functionette");
    if (isdigit(func[0]))
        throw std::invalid_argument("incorrect functionette name \'" + func + "\'; name begins with a digit");
    
    // extract name
    for (std::string::size_type i = 0; i < func.size(); ++i)
    {
        if (func[i] == '(')
        {
            // perform a sanity check here
            if (func.back() != ')')
                throw std::invalid_argument("functionette \'" + func + "\' is not valid");
            m_name = func.substr(0, i);
            func.erase(0,i);            // delete name portion
            func.erase(func.begin());   // delete beginning parantheses
            func.erase(func.size()-1);  // delete closing parantheses
        }
    }
    
    if (m_name.size() == 0)
        throw std::invalid_argument("failed to extract name of functionette");
    
    // debug: check what's left after extracting name
    std::cout << func << "\n";
    
    // extract individual arguments and put them in m_args
    std::string::size_type i = 0;
    while (func.size() != 0)
    {
        if (func[i] == ' ')
        {
            func.erase(func.begin()+i);
            i = 0;
            continue;
        }
        if (func[i] == ',')
        {
            m_args.push_back(func.substr(0, i));
            func.erase(0,i+1);
            i = 0;
            continue;
        }
        if (i == func.size())
        {
            m_args.push_back(func);
            func.erase(0, i);
            i = 0;
            continue;
        }
        std::cout << i << ": " << func << "\n";
        ++i;
    }
}
