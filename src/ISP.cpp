#include "ISP.hpp"

ISP::ISP()
{
    clearall();
}

ISP::ISP(std::vector<engine> vec)
{
    clearall();
    set_engines(vec);
}

ISP::ISP(engine eng)
{
    clearall();
    insert_engine(eng);
}

ISP::ISP(double isp, double thrust)
{
    clearall();
    insert_engine(isp, thrust);
}

double ISP::calculate()
{
    if (engines.size() == 0)
        throw std::invalid_argument("no data in input");
    
    double thrustSum = 0;
    double ratioSum = 0;
    for (auto& it : engines)
    {
        thrustSum += it.second;
        ratioSum += it.second / it.first;
    }
    
    m_result = thrustSum / ratioSum;
    return m_result;
}

void ISP::clearall()
{
    clearresult();
    clearargs();
}

void ISP::clearresult()
{
    m_result = 0;
}

void ISP::clearargs()
{
    engines = std::vector<engine> {};
}

const std::vector<engine>& ISP::get_engines()
{
    const std::vector<engine>& out_eng = engines;
    return out_eng;
}

void ISP::set_engines(std::vector<engine> new_engines)
{
    if (new_engines.size() == 0)
        throw std::length_error("input engine list has no elements");
    
    for (auto& it : new_engines)
    {
        if (it.first <= 0)
            throw std::domain_error("isp cannot be less than or equal to 0");
        if (it.second <= 0)
            throw std::domain_error("thrust cannot be less than or equal to 0");
    }
    
    engines = new_engines;
}

void ISP::insert_engine(engine new_engine)
{
    if (new_engine.first <= 0)
        throw std::domain_error("isp cannot be less than or equal to 0");
    if (new_engine.second <= 0)
        throw std::domain_error("thrust cannot be less than or equal to 0");
    
    engines.push_back(new_engine);
}

void ISP::insert_engine(double isp, double thrust)
{    
    insert_engine(engine(isp, thrust));
}

double ISP::operator()(std::vector<engine> vec)
{
    clearall();
    set_engines(vec);
    return calculate();
}

double ISP::operator()(engine eng)
{
    clearall();
    insert_engine(eng);
    return calculate();
}

double ISP::operator()(double isp, double thrust)
{
    clearall();
    insert_engine(isp, thrust);
    return calculate();
}
