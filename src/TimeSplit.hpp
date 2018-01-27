#ifndef TIMESPLIT_H
#define TIMESPLIT_H

#include <utility>
#include <stdexcept>

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
    std::pair<int, double> getResult();
    void getResult(int& minutes, double& seconds);
    
    void set_inputTime(std::pair<int, double>);
    void set_inputTime(int, double);
};

#endif
