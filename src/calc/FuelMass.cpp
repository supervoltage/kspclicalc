#include "FuelMass.hpp"
#include "phys.hpp"
#include <cmath>

#define MAX_ARG_COUNT 6
#define MIN_ARG_COUNT 6

FuelMass::FuelMass()
{
    clearall();
}

FuelMass::FuelMass(double new_deltaV, double new_isp, int new_nEngines,
                   double new_massEngine, double new_massPayload,
                   double new_fullEmptyRatio)
{
    clearall();
    setargs(new_deltaV, new_isp, new_nEngines, new_massEngine, new_massPayload,
            new_fullEmptyRatio);
}

FuelMass::FuelMass(const std::vector<std::string>& in_arg_list)
{
    setargs(in_arg_list);
}

double FuelMass::calculate()
{
    double reqWetToDry = exp(deltaV / (phys::g * isp));
    double mass = (reqWetToDry - 1)*((nEngines*massEngine) + massPayload)*fullEmptyRatio;
    double ratio = fullEmptyRatio - reqWetToDry;
    m_result = mass / ratio;
    return m_result;
}

void FuelMass::clearall()
{
    clearresult();
    clearargs();
}

void FuelMass::clearresult()
{
    m_result = 0;
}

void FuelMass::clearargs()
{
    deltaV = 0;
    isp = 0;
    nEngines = 0;
    massEngine = 0;
    massPayload = 0;
    fullEmptyRatio = 0;
}

void FuelMass::setargs(double new_deltaV, double new_isp, int new_nEngines,
                       double new_massEngine, double new_massPayload,
                       double new_fullEmptyRatio)
{
    set_deltaV          (new_deltaV);
    set_isp             (new_isp);
    set_nEngines        (new_nEngines);
    set_massEngine      (new_massEngine);
    set_massPayload     (new_massPayload);
    set_fullEmptyRatio  (new_fullEmptyRatio);
}

void FuelMass::setargs(const std::vector<std::string>& in_arg_list)
{
    std::vector<std::string>::size_type arg_list_count = in_arg_list.size();
    if (arg_list_count >= MIN_ARG_COUNT && arg_list_count <= MAX_ARG_COUNT)
    {
        // we can use direct indexing of the input argument list as we know we definitely have
        // enough arguments
        set_deltaV(atof(in_arg_list[0].c_str()));
        set_isp(atof(in_arg_list[1].c_str()));
        set_nEngines(atoi(in_arg_list[2].c_str()));
        set_massEngine(atof(in_arg_list[3].c_str()));
        set_massPayload(atof(in_arg_list[4].c_str()));
        set_fullEmptyRatio(atof(in_arg_list[5].c_str()));
    }
    else
        throw std::invalid_argument("invalid number of arguments");
}

void FuelMass::set_deltaV(double new_deltaV)
{
    if (new_deltaV <= 0)
        throw std::domain_error("deltaV cannot be less than or equal to 0");
    deltaV = new_deltaV;
}

void FuelMass::set_isp(double new_isp)
{
    if (new_isp <= 0)
        throw std::domain_error("isp cannot be less than or equal to 0");
    isp = new_isp;
}

void FuelMass::set_nEngines(int new_nEngines)
{
    if (new_nEngines <= 0)
        throw std::domain_error("nEngines cannot be less than or equal to 0");
    nEngines = new_nEngines;
}

void FuelMass::set_massEngine(double new_massEngine)
{
    if (new_massEngine <= 0)
        throw std::domain_error("massEngine cannot be less than or equal to 0");
    massEngine = new_massEngine;
}

void FuelMass::set_massPayload(double new_massPayload)
{
    if (new_massPayload <= 0)
        throw std::domain_error("massPayload cannot be less than or equal to 0");
    massPayload = new_massPayload;
}

void FuelMass::set_fullEmptyRatio(double new_fullEmptyRatio)
{
    if (new_fullEmptyRatio <= 0)
        throw std::domain_error("fullEmptyRatio cannot be less than or equal to 0");
    fullEmptyRatio = new_fullEmptyRatio;
}

double FuelMass::get_deltaV()
{
    return deltaV;
}

double FuelMass::get_isp()
{
    return isp;
}

int FuelMass::get_nEngines()
{
    return nEngines;
}

double FuelMass::get_massEngine()
{
    return massEngine;
}

double FuelMass::get_massPayload()
{
    return massPayload;
}

double FuelMass::get_fullEmptyRatio()
{
    return fullEmptyRatio;
}

double FuelMass::operator()(double new_deltaV, double new_isp, int new_nEngines,
                            double new_massEngine, double new_massPayload,
                            double new_fullEmptyRatio)
{
    clearall();
    setargs(new_deltaV, new_isp, new_nEngines, new_massEngine, new_massPayload,
            new_fullEmptyRatio);
    return calculate();
}

std::ostream& operator<< (std::ostream& os, const FuelMass& fm)
{
    os << fm.getResult();
    return os;
}
