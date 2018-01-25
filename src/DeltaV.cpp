#include "DeltaV.hpp"
#include "phys.hpp"

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
    fuelMass = newFuelMass;
}

void DeltaV::set_fuelMass(std::vector<double> vec)
{
    fuelMass = 0;
    for(auto& it : vec)
    {
        fuelMass += it;
    }
}

void DeltaV::set_isp(double newIsp)
{
    isp = newIsp;
}

void DeltaV::set_totalMass(double newTotalMass)
{
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
