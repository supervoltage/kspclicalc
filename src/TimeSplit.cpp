#include "TimeSplit.hpp"
#include <cmath>

void TimeSplit::clearargs()
{
    input_time = std::pair<int, double> {0, 0};
}

void TimeSplit::clearresult()
{
    result_time = std::pair<int, double> {0, 0};
}

void TimeSplit::clearall()
{
    clearargs();
    clearresult();
}

void TimeSplit::calculate()
{
    if (input_time.second >= 60)
        throw std::domain_error("invalid number of seconds");
    
    if (input_time.first != 0)
    {
        double wseconds = ((input_time.first*60) + input_time.second) / 120;
        double minutes = 0;
        double seconds = modf(wseconds, &minutes) * 60;
        result_time.first = minutes;
        result_time.second = seconds;
    }
    else
    {
        double seconds = input_time.second / 2;
        result_time.first = 0;
        result_time.second = seconds;
    }
}

std::pair<int, double> TimeSplit::get_inputTime()
{
    return input_time;
}

void TimeSplit::get_inputTime(int& minutes, double& seconds)
{
    minutes = input_time.first;
    seconds = input_time.second;
}

std::pair<int, double> TimeSplit::getResult()
{
    return result_time;
}

void TimeSplit::getResult(int& minutes, double& seconds)
{
    minutes = result_time.first;
    seconds = result_time.second;
}


void TimeSplit::set_inputTime(std::pair<int, double> new_input_time)
{
    input_time = new_input_time;
}

void TimeSplit::set_inputTime(int min, double sec)
{
    std::pair<int, double> new_input_time(min, sec);
    input_time = new_input_time;
}
