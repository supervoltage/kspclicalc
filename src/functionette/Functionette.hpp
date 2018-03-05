#ifndef FUNCTIONETTE_H
#define FUNCTIONETTE_H

// this class of objects is used primarily for managing a specific kind of input called a Functionette

// a Functionette is of the below format:
//      func(args)
// where 'func' is the name of the functionette and 'args' is a comma-delimited list of arguments to
// the functionette.

/* Functionette will be an abstract base class and the programmer will need to derive other
 * Functionette-based classes from which one can define how a specific functionette looks like.
 * 
 * For instance, one could derive a Functionette to calculate DeltaV called FuncDV. The derived class
 * could have hard-coded limits for how many arguments there should be and hard-coded argument names.
 * 
 * This will simplify the base class quite a bit and then we only need the following variables in a
 * base class: m_name, m_args
 * 
 * 
*/

// I should also rethink the purpose of Functionette. It will in the first place be used as a means
// of checking if an input Functionette is valid (for instance, isp(10, 20, 10, 20) ), but should it
// also be performing any calculations? Or should we return a struct or similar containing the arg
// list for the caller to deal with and perform the calculation?

// If we rely on inheritance we can include the calculation portion straight into the derived class.
// Then we can just calculate it. But should we go this further step? It will make it more difficult
// to add further parts to this program, I'd think.

// Argh, design choices..

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
    std::vector<std::string> get_args() const;  // get all args; first is name, second is value
    
    void store(std::string functionette);
};

#endif
