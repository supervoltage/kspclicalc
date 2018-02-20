#include "TimeSplit.hpp"
#include <cmath>
#include <sstream>

TimeSplit::TimeSplit()
{
    clearall();
}

TimeSplit::TimeSplit(std::pair<int, double> new_input_time)
{
    clearall();
    set_inputTime(new_input_time);
}

TimeSplit::TimeSplit(int new_min, double new_sec)
{
    clearall();
    set_inputTime(new_min, new_sec);
}

TimeSplit::TimeSplit(const std::vector<std::string>& in_arg_list)
{
    setargs(in_arg_list);
}

void TimeSplit::setargs(const std::vector<std::string>& in_arg_list)
{
    if(in_arg_list.size() < 2 || in_arg_list.size() > 3)
        throw std::invalid_argument("invalid number of arguments, must be exactly 2 arguments");
    
    m_input_time.first  = atof(in_arg_list[0].c_str());
    m_input_time.second = atof(in_arg_list[1].c_str());
}

void TimeSplit::clearargs()
{
    set_inputTime(0, 0);
}

void TimeSplit::clearresult()
{
    m_result = 0;
}

void TimeSplit::clearall()
{
    clearargs();
    clearresult();
}

double TimeSplit::calculate()
{
    if (m_input_time.second >= 60)
        throw std::domain_error("invalid number of seconds");
    
    if (m_input_time.first != 0)
    {
        m_result = ((m_input_time.first*60) + m_input_time.second) / 2;
        /*
        double minutes = 0;
        double seconds = modf(wseconds, &minutes) * 60;
        result_time.first = minutes;
        result_time.second = seconds;
        */
    }
    else
    {
        m_result = m_input_time.second / 2;
        /*
        result_time.first = 0;
        result_time.second = seconds;
        */
    }
    return m_result;
}

std::pair<int, double> TimeSplit::get_inputTime()
{
    return m_input_time;
}

void TimeSplit::get_inputTime(int& minutes, double& seconds)
{
    minutes = m_input_time.first;
    seconds = m_input_time.second;
}


void TimeSplit::set_inputTime(std::pair<int, double> new_input_time)
{
    if (new_input_time.first < 0)
        throw std::domain_error("new input time value \"minutes\" cannot be lower than 0 minutes");
    if (new_input_time.second < 0 || new_input_time.second >= 60)
        throw std::domain_error("new input time value \"seconds\" cannot be lower than 0 seconds or higher than or equal to 60 seconds");
    
    m_input_time = new_input_time;
}

void TimeSplit::set_inputTime(int min, double sec)
{
    std::pair<int, double> new_input_time(min, sec);
    set_inputTime(new_input_time);
}


double TimeSplit::operator()(std::pair<int, double> in_time)
{
    clearall();
    set_inputTime(in_time);
    return calculate();
}

double TimeSplit::operator()(int min, double sec)
{
    return (*this)(std::pair<int, double> {min, sec});
}

std::string seconds_to_minsAndSecs(double secs)
{
    std::stringstream ss;
    if (secs < 60)
    {
        ss << "0min" << secs << "sec";
    }
    else
    {
        double minutes = 0;
        double seconds = modf(secs/60, &minutes) * 60;
        ss << minutes << "min" << seconds << "sec";
    }
    
    return ss.str();
}
