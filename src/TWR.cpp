#include "TWR.hpp"

TWR::TWR()
{
    clearall();
}

TWR::TWR(double new_totalThrust, double new_totalMass)
{
    clearall();
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
    if (newTotalThrust <= 0)
        throw std::domain_error("totalThrust cannot be less than or equal to 0");
    totalThrust = newTotalThrust;
}

void TWR::set_totalThrust(std::vector<double> vec)
{
    if (vec.size() == 0)
        throw std::invalid_argument("no data in input");
    
    double tmp_totalThrust = 0;
    for (auto& it : vec)
    {
        tmp_totalThrust += it;
    }
    
    set_totalThrust(tmp_totalThrust);
}

void TWR::set_totalMass(double newTotalMass)
{
    if (newTotalMass <= 0)
        throw std::domain_error("totalMass cannot be less than or equal to 0");
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

double TWR::operator()(double new_totalThrust, double new_totalMass)
{
    clearall();
    setargs(new_totalThrust, new_totalMass);
    return calculate();
}

std::ostream& operator<< (std::ostream& os, const TWR& twr)
{
    os << twr.getResult();
    return os;
}
