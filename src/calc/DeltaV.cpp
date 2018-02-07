#include "DeltaV.hpp"
#include "phys.hpp"
#include <cstdlib>

#define MAX_ARG_COUNT 3
#define MIN_ARG_COUNT 3

DeltaV::~DeltaV()
{}

DeltaV::DeltaV()
{
    clearall();
}

DeltaV::DeltaV(double new_fuelMass, double new_isp, double new_totalMass)
{
    clearall();
    setargs(new_fuelMass, new_isp, new_totalMass);
}

DeltaV::DeltaV(const std::vector<std::string>& in_arg_list)
{
    setargs(in_arg_list);
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
    
    set_fuelMass(tmpfuelMass);
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

void DeltaV::setargs(double new_isp, double new_totalMass, double new_fuelMass)
{
    set_isp(new_isp);
    set_totalMass(new_totalMass);
    set_fuelMass(new_fuelMass);
}

void DeltaV::setargs(const std::vector<std::string>& in_arg_list)
{
    std::vector<std::string>::size_type arg_list_count = in_arg_list.size();
    if (arg_list_count >= MIN_ARG_COUNT && arg_list_count <= MAX_ARG_COUNT)
    {
        // we can use direct indexing of the input argument list as we know we definitely have
        // enough arguments
        set_isp(atof(in_arg_list[0].c_str()));
        set_totalMass(atof(in_arg_list[1].c_str()));
        set_fuelMass(atof(in_arg_list[2].c_str()));
    }
    else
        throw std::invalid_argument("invalid number of arguments");
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

double DeltaV::operator()(double new_fuelMass, double new_isp, double new_totalMass)
{
    clearall();
    setargs(new_fuelMass, new_isp, new_totalMass);
    return calculate();
}

std::ostream& operator<< (std::ostream& os, const DeltaV& dv)
{
    os << dv.getResult();
    return os;
}
