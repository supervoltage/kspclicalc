#ifndef TIMESPLIT_H
#define TIMESPLIT_H

#include <utility>
#include <stdexcept>
#include <ostream>

// inherit from Calculator and store result in m_result as seconds, usage of getResult() will return
// just the number of seconds
// provide a function to convert the number of seconds (double) into a pair of values min and sec (string), non-class

class TimeSplit
{
private:
    std::pair<int, double> input_time;
    std::pair<int, double> result_time;
public:
    TimeSplit();
    TimeSplit(std::pair<int, double>);
    TimeSplit(int, double);
    
    void clearargs();
    void clearresult();
    void clearall();
    void calculate();
    
    std::pair<int, double> get_inputTime();
    void get_inputTime(int& minutes, double& seconds);
    std::pair<int, double> getResult() const;
    void getResult(int& minutes, double& seconds);
    
    void set_inputTime(std::pair<int, double>);
    void set_inputTime(int, double);
    
    std::pair<int, double> operator()(std::pair<int, double>);
    std::pair<int, double> operator()(int, double);
};

std::ostream& operator<< (std::ostream& os, const TimeSplit& ts);

#endif
