#include "Functionette.hpp"
#include <cctype>
#include <stdexcept>

// constructors
Functionette::Functionette(const Functionette& func)      // copy constructor
{
    m_name = func.m_name;
    m_args = func.m_args;
}

Functionette::Functionette(std::string func_str)          // build Functionette directly from functionette string
{
    store(func_str);
}


// defined in .cpp file as these do more checks
void Functionette::set_name(std::string name)
{
    if (name.size() == 0)
        throw std::invalid_argument("invalid functionette name; no name specified");
    if (isdigit(name[0]))
        throw std::invalid_argument("invalid functionette name; name begins with a digit: " + name);
    
    m_name = name;
}

void Functionette::set_args(std::vector<std::string> args)
{
    for (const auto& it: args)
    {
        if (it.size() == 0)
            throw std::invalid_argument("invalid argument to functionette; no argument specified");
    }
    
    m_args = args;
}

void Functionette::insert_arg(std::string arg)
{
    if (arg.size() == 0)
        throw std::invalid_argument("invalid argument to functionette; no argument specified");
    
    m_args.push_back(arg);
}

// general methods
void Functionette::store(std::string func)                // takes a functionette string and sets m_name and m_args
{
    // TODO: algorithm to read functionettes and stick them into the object's variables
    // Examples below:
    /*  cpu(500) -> m_name="cpu"; m_args={"500"};
     *  dv(10, 20, 30) -> m_name="dv"; m_args={"10","20","30"};
     *  dv(10, 20, cpu(300)) -> m_name="dv"; m_args={"10","20","cpu(300)"} -> m_args{"10","20","x"} (where x is the result of cpu(300) )
    */
}
