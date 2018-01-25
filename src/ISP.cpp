#include "ISP.hpp"

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
    engines = new_engines;
}

void ISP::insert_engine(engine new_engine)
{
    engines.push_back(new_engine);
}

void ISP::insert_engine(double isp, double thrust)
{
    engines.push_back(engine(isp, thrust));
}
