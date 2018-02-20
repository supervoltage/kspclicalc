#ifndef TIMESPLIT_H
#define TIMESPLIT_H

#include <utility>
#include <stdexcept>
#include <ostream>
#include <string>
#include "Calculator.hpp"

// inherit from Calculator and store result in m_result as seconds, usage of getResult() will return
// just the number of seconds
// provide a function to convert the number of seconds (double) into a pair of values min and sec (string), non-class

class TimeSplit : public Calculator
{
private:
    std::pair<int, double> m_input_time;
public:
    TimeSplit();
    TimeSplit(std::pair<int, double>);
    TimeSplit(int, double);
    TimeSplit(const std::vector<std::string>& in_arg_list);
    
    virtual void setargs(const std::vector<std::string>& in_arg_list);
    virtual void clearargs();
    virtual void clearresult();
    virtual void clearall();
    virtual double calculate();
    
    std::pair<int, double> get_inputTime();
    void get_inputTime(int& minutes, double& seconds);
    
    void set_inputTime(std::pair<int, double>);
    void set_inputTime(int, double);
    
    double operator()(std::pair<int, double>);
    double operator()(int, double);
};

std::string seconds_to_minsAndSecs(double secs);

#endif
