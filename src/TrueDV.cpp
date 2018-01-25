#include "TrueDV.hpp"

double TrueDV::calculate()
{
    DeltaV dv;
    dv.set_fuelMass(fuelMass);
    dv.set_totalMass(totalMass);
    dv.set_isp(atmISP);
    dv.calculate();
    
    double atmDV = dv.getResult();
    
    dv.set_isp(vacISP);
    dv.calculate();
    double vacDV = dv.getResult();
    
    m_result = (((atmDV - escapeDV) * vacDV) / atmDV) + escapeDV;
    return m_result;
}

void TrueDV::clearall()
{
    clearresult();
    clearargs();
}

void TrueDV::clearresult()
{
    m_result = 0;
}

void TrueDV::clearargs()
{
    atmISP = 0;
    vacISP = 0;
    escapeDV = 0;
    totalMass = 0;
    fuelMass = 0;
}


void TrueDV::set_atmISP(double new_atmISP)
{
    atmISP = new_atmISP;
}

void TrueDV::set_vacISP(double new_vacISP)
{
    vacISP = new_vacISP;
}

void TrueDV::set_escapeDV(double new_escapeDV)
{
    escapeDV = new_escapeDV;
}

void TrueDV::set_totalMass(double new_totalMass)
{
    totalMass = new_totalMass;
}

void TrueDV::set_fuelMass(double new_fuelMass)
{
    fuelMass = new_fuelMass;
}

void TrueDV::set_fuelMass(std::vector<double> new_fuelMasses)
{
    fuelMass = 0;
    for (auto& it : new_fuelMasses)
    {
        fuelMass += it;
    }
}

void TrueDV::setargs(double new_atmISP, double new_vacISP, double new_escapeDV,
                     double new_totalMass, double new_fuelMass)
{
    atmISP = new_atmISP;
    vacISP = new_vacISP;
    escapeDV = new_escapeDV;
    totalMass = new_totalMass;
    fuelMass = new_fuelMass;
}

double TrueDV::get_atmISP()
{
    return atmISP;
}
double TrueDV::get_vacISP()
{
    return vacISP;
}
double TrueDV::get_escapeDV()
{
    return escapeDV;
}
double TrueDV::get_totalMass()
{
    return totalMass;
}
double TrueDV::get_fuelMass()
{
    return fuelMass;
}
