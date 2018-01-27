#include "TWR.hpp"

TWR::TWR()
{
    clearall();
}

TWR::TWR(double new_totalThrust, double new_totalMass)
{
    setargs(new_totalThrust, new_totalMass);
}

double TWR::get_totalThrust()
{
    return totalThrust;
}

double TWR::get_totalMass()
{
    return totalMass;
}

void TWR::set_totalThrust(double newTotalThrust)
{
    totalThrust = newTotalThrust;
}

void TWR::set_totalThrust(std::vector<double> vec)
{
    totalThrust = 0;
    for (auto& it : vec)
    {
        totalThrust += it;
    }
}

void TWR::set_totalMass(double newTotalMass)
{
    totalMass = newTotalMass;
}

void TWR::setargs(double new_totalThrust, double new_totalMass)
{
    set_totalThrust(new_totalThrust);
    set_totalMass(new_totalMass);
}


double TWR::calculate()
{
    m_result = totalThrust / (totalMass * phys::g);
    return m_result;
}

void TWR::clearall()
{
    clearresult();
    clearargs();
}

void TWR::clearresult()
{
    m_result = 0;
}

void TWR::clearargs()
{
    totalThrust = 0;
    totalMass = 0;
}
