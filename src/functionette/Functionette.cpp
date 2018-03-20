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

#include <iostream>

// general methods
void Functionette::store(std::string func)                // takes a functionette string and sets m_name and m_args
{
    // TODO: algorithm to read functionettes and stick them into the object's variables
    // Examples below:
    /*  cpu(500) -> m_name="cpu"; m_args={"500"};
     *  dv(10, 20, 30) -> m_name="dv"; m_args={"10","20","30"};
     *  dv(10, 20, cpu(300)) -> m_name="dv"; m_args={"10","20","cpu(300)"} -> m_args{"10","20","30"} (where 30 is the result of cpu(300) )
    */
    
    // first we perform some legality checks to ensure the input is of valid format
    // must have a name at least one char in length and to have the two chars '(' and ')'
    if (func.size() < 3)
        throw std::invalid_argument("functionette \'" + func + "\' is invalid; too short");
    
    // first character must not be a digit
    if (isdigit(func[0]))
        throw std::invalid_argument("functionette \'" + func + "\' is invalid: name begins with a digit");
    
    // must have equal numbers of '(' and ')' characters
    {
        int openc = 0;    // balance between '(' and ')' characters, should be 0 by end of loop
        int closec = 0;
        for (const auto& it : func)
        {
            if (it == '(')
                ++openc;
            if (it == ')')
                ++closec;
        }
        if (openc != closec)
            throw std::invalid_argument("functionette \'" + func + "\' is invalid; imbalanced () characters");
        if (openc == closec && openc == 0)
            throw std::invalid_argument("functionette \'" + func + "\' is invalid; must have at least one () pair");
    }
    
    // now we can process the input as we're sure it's correct by this point
    // extract the name (portion from beginning of string until first '(' character)
    {
        // find where is the first '(' char
        int pos = 0;
        while (func[pos] != '(')
            ++pos;
        // extract the portion [0, pos) into m_name
        m_name = func.substr(0, pos);
        
        // remove the name portion from input string
        func.erase(0, pos);
        
        // erase first and last '(' and ')' characters
        func.erase(func.begin());
        func.erase(--func.end());
    }
    
    // TODO: extract all the arguments separately
    
    // isp(20, cpu(300))
    
    while (func.size() != 0)    // until we run out of input run the below loop
    {
        std::string::size_type pos = 0;
        int pbal = 0;                               // balance between parantheses
        
        if (func[pos] == ' ')
        {
            func.erase(pos,1);
            continue;
        }
        
        for (pos = 0; pos < func.size(); ++pos)
        {                
            if (func[pos] == '(')                   // check if we're opening an argument list
                ++pbal;
            else if (func[pos] == ')')
                --pbal;
            
            if (func[pos] == ',' && (pbal == 0))    // check if it's time to take out the argument
            {
                m_args.push_back(func.substr(0,pos));
                func.erase(0,pos+1);
                break;
            }
            
            if (pos == func.size()-1)
            {
                m_args.push_back(func);
                func.erase(0,pos+1);
                break;
            }
        }
    }
}
