#include "TrueDV.hpp"

TrueDV()
{
    clearall();
}

TrueDV(double new_atmISP, double new_vacISP, double new_escapeDV, 
       double new_totalMass, double new_fuelMass)
{
    clearall();
    setargs(new_atmISP, new_vacISP, new_escapeDV, new_totalMass, new_fuelMass);
}

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
    if(new_atmISP <= 0)
        throw std::domain_error("atmISP cannot be less than or equal to 0");

    atmISP = new_atmISP;
}

void TrueDV::set_vacISP(double new_vacISP)
{
    if(new_vacISP <= 0)
        throw std::domain_error("vacISP cannot be less than or equal to 0");
    
    vacISP = new_vacISP;
}

void TrueDV::set_escapeDV(double new_escapeDV)
{
    if(new_escapeDV <= 0)
        throw std::domain_error("escapeDV cannot be less than or equal to 0");
    
    escapeDV = new_escapeDV;
}

void TrueDV::set_totalMass(double new_totalMass)
{
    if(new_totalMass <= 0)
        throw std::domain_error("totalMass cannot be less than or equal to 0");
    
    totalMass = new_totalMass;
}

void TrueDV::set_fuelMass(double new_fuelMass)
{
    if(new_fuelMass <= 0)
        throw std::domain_error("fuelMass cannot be less than or equal to 0");
    
    fuelMass = new_fuelMass;
}

void TrueDV::set_fuelMass(std::vector<double> new_fuelMasses)
{
    if(new_fuelMasses.size() == 0)
        throw std::invalid_argument("no elements in input");
        
    double tmp_fuelMass = 0;
    for (auto& it : new_fuelMasses)
    {
        tmp_fuelMass += it;
    }
    
    set_fuelMass(tmp_fuelMass);
}

void TrueDV::setargs(double new_atmISP, double new_vacISP, double new_escapeDV,
                     double new_totalMass, double new_fuelMass)
{
    set_atmISP(new_atmISP);
    set_vacISP(new_vacISP);
    set_escapeDV(new_escapeDV);
    set_totalMass(new_totalMass);
    set_fuelMass(new_fuelMass);
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
