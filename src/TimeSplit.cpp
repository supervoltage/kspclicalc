#include "TimeSplit.hpp"
#include <cmath>

TimeSplit()
{
    clearall();
}

TimeSplit(std::pair<int, double> new_input_time)
{
    clearall();
    set_inputTime(new_input_time);
}

TimeSplit(int new_min, double new_sec)
{
    clearall();
    set_inputTime(new_min, new_sec);
}

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
    if (new_input_time.first < 0)
        throw std::domain_error("new input time value \"minutes\" cannot be lower than 0 minutes");
    if (new_input_time.second < 0 || new_input_time.second >= 60)
        throw std::domain_error("new input time value \"seconds\" cannot be lower than 0 seconds or higher than or equal to 60 seconds");
    
    input_time = new_input_time;
}

void TimeSplit::set_inputTime(int min, double sec)
{
    std::pair<int, double> new_input_time(min, sec);
    set_inputTime(new_input_time);
}
