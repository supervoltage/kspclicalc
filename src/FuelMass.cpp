#include "FuelMass.hpp"
#include "phys.hpp"
#include <cmath>

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
