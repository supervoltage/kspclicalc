#include "DeltaV.hpp"
#include "phys.hpp"

DeltaV::DeltaV()
{
    fuelMass = 0;
    isp = 0;
    totalMass = 0;
}

DeltaV::DeltaV(double new_fuelMass, double new_isp, double new_totalMass)
{
    setargs(new_fuelMass, new_isp, new_totalMass);
}

double DeltaV::get_fuelMass()
{
    return fuelMass;
}

double DeltaV::get_isp()
{
    return isp;
}

double DeltaV::get_totalMass()
{
    return totalMass;
}

void DeltaV::set_fuelMass(double newFuelMass)
{
    if (newFuelMass <= 0)
        throw std::domain_error("fuel mass cannot be less than or equal to 0");
    
    fuelMass = newFuelMass;
}

void DeltaV::set_fuelMass(std::vector<double> vec)
{
    double tmpfuelMass = 0;
    for(auto& it : vec)
    {
        tmpfuelMass += it;
    }
    if (tmpfuelMass <= 0)
        throw std::domain_error("fuel mass cannot be less than or equal to 0");
    
    fuelMass = tmpfuelMass;
}

void DeltaV::set_isp(double newIsp)
{
    if (newIsp <= 0)
        throw std::domain_error("isp cannot be less than or equal to 0");
    isp = newIsp;
}

void DeltaV::set_totalMass(double newTotalMass)
{
    if (newTotalMass <= 0)
        throw std::domain_error("total mass cannot be less than or equal to 0");
    totalMass = newTotalMass;
}

void DeltaV::setargs(double new_fuelMass, double new_isp, double new_totalMass)
{
    set_fuelMass(new_fuelMass);
    set_isp(new_isp);
    set_totalMass(new_totalMass);
}


// base class pure virtual functions implementations

double DeltaV::calculate()
{
    m_result = log(totalMass / (totalMass - fuelMass)) * isp * phys::g;
    return m_result;
}

void DeltaV::clearall()
{
    clearresult();
    clearargs();
}

void DeltaV::clearresult()
{
    m_result = 0;
}

void DeltaV::clearargs()
{
    fuelMass = 0;
    isp = 0;
    totalMass = 0;
}
