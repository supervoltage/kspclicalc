#include "FuelMass.hpp"
#include "phys.hpp"
#include <cmath>

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
    deltaV = new_deltaV;
    isp = new_isp;
    nEngines = new_nEngines;
    massEngine = new_massEngine;
    massPayload = new_massPayload;
    fullEmptyRatio = new_fullEmptyRatio;
}

void FuelMass::set_deltaV(double new_deltaV)
{
    deltaV = new_deltaV;
}

void FuelMass::set_isp(double new_isp)
{
    isp = new_isp;
}

void FuelMass::set_nEngines(int new_nEngines)
{
    nEngines = new_nEngines;
}

void FuelMass::set_massEngine(double new_massEngine)
{
    massEngine = new_massEngine;
}

void FuelMass::set_massPayload(double new_massPayload)
{
    massPayload = new_massPayload;
}

void FuelMass::set_fullEmptyRatio(double new_fullEmptyRatio)
{
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
