#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdexcept>
#include <vector>
#include <string>

class Calculator {
protected:
    double m_result;
public: 
    virtual double calculate() = 0;
    virtual void clearall() = 0;
    virtual void clearresult() = 0;
    virtual void clearargs() = 0;
    
    virtual void setargs(std::vector<std::string> in_arg_list) = 0;
    
    double getResult() const;
};

#endif
