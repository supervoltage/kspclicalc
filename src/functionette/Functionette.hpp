#ifndef FUNCTIONETTE_H
#define FUNCTIONETTE_H

// this class of objects is used primarily for managing a specific kind of input called a Functionette

// a Functionette is of the below format:
//      func(args)
// where 'func' is the name of the functionette and 'args' is a comma-delimited list of arguments to
// the functionette.

// This class will take the functionette string and split its contents up correctly for later input
// management of some sort.

#include <string>
#include <vector>

class Functionette
{
private:
    std::string m_name;    
    std::vector<std::string> m_args;
    // a vector to store all the arguments obtained via the store() function
    
public:
    // constructors and destructors
    Functionette();
    Functionette(std::string name, std::vector<std::string> args);
    Functionette(std::string functionette_string);
    
    // getters and setters
    std::string get_name() const;
    void set_name(std::string new_name);
    
    std::string operator[] (int arg_num); // obtain argument value from one specific argument name
    std::vector<std::string> get_args() const;  // get all args; first is name, second is value
    
    void parse(std::string functionette);
};

#endif
