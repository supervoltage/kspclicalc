#ifndef FUNCTIONETTE_H
#define FUNCTIONETTE_H

// this class of objects is used primarily for managing a specific kind of input called a Functionette

// a Functionette is of the below format:
//      func(args)
// where 'func' is the name of the functionette and 'args' is a comma-delimited list of arguments to
// the functionette.
// Functionettes can be nested inside of each other like below:
//      func(arg1, func2(arg2), func3(arg3, arg4, arg5) func4(func5(test)))
// Which will calculate the values of the inner functionettes before moving on to the outer functionettes,
// essentially unwinding the stack of calls.

// This class will take the functionette string and split its contents up correctly for later input
// management of some sort.

#include <string>
#include <vector>

class Functionette
{
private:
    std::string m_name;                 // name of the functionette
    std::vector<std::string> m_args;    // store all the arguments of the comma-delimited functionette string

protected:
    // defined in .cpp file as these do more checks
    void set_name(std::string name);
    void set_args(std::vector<std::string> args);
    void insert_arg(std::string arg);

public:
    // constructors
    Functionette() {};                          // make empty Functionette
    Functionette(const Functionette& func);     // copy constructor
    Functionette(std::string func_str);         // build Functionette directly from functionette string
    
    // getters and setters
    std::string get_name() const              { return m_name;   }
    std::vector<std::string> get_args() const { return m_args;   }
    std::vector<std::string>::size_type get_argc() const { return m_args.size(); }

    // general methods
    void store(std::string func);               // takes a functionette string and sets m_name and m_args
};

#endif
