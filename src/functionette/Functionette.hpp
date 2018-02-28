#ifndef FUNCTIONETTE_H
#define FUNCTIONETTE_H

// this class of objects is used primarily for managing a specific kind of input called a Functionette

// a Functionette is of the below format:
//      func(args)
// where 'func' is the name of the functionette and 'args' is a comma-delimited list of arguments to
// the functionette.

#include <string>
#include <vector>
#include <utility>
#include <map>

class Functionette
{
private:
    std::string m_name;
    
    std::pair<int, int> m_arg_bounds;
    // minimum and maximum amount of arguments to a function
    // negative numbers are used to indicate infinity
    // min value cannot be infinite
    // max value must be larger than min value
    
    std::map<std::string, std::string> m_arg_helper;
    // list of argument names and their descriptions to the functionette
    // This contains information solely for the end user to refer to so they are aware what values
    // are expected in the input to the functionette.
    // first string is arg name, second string is argument description
    
    std::vector<std::string> m_args;
    // a vector to store all the arguments obtained via the store() function

public:
    // constructors and destructors
    Functionette(std::string name, int min, int max, std::map<std::string, std::string> helper);
    
    // getters and setters
    std::string get_name() const;
    void set_name(std::string new_name);
    
    std::pair<int, int> get_bounds() const;
    void get_bounds(int& min, int& max) const;
    void set_bounds(std::pair<int, int> new_bounds);
    void set_bounds(int min, int max);
    
    std::map<std::string, std::string> get_helper() const;
    void set_helper(std::map<std::string, std::string> new_helper);
    void insert_helper_pair(std::pair<std::string, std::string> pair);
    void insert_helper_pair(std::string name, std::string desc);
    
    std::string operator[] (std::string searchterm); // obtain argument value from one specific argument name
    std::map<std::string, std::string> get_args() const;  // get all args; first is name, second is value
    
    void store(std::string functionette);
};

#endif
