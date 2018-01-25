#ifndef TRUEDV_H
#define TRUEDV_H

#include "Calculator.hpp"
#include "DeltaV.hpp"
#include <vector>

class TrueDV : public Calculator
{
private:
    double atmISP;
    double vacISP;
    double escapeDV;
    double totalMass;
    double fuelMass;
public:
    virtual double calculate();
    virtual void clearall();
    virtual void clearresult();
    virtual void clearargs();
    
               // atmISP vacISP escapeDV totalMass fuelMass
    void setargs(double, double, double, double, double);
    
    void set_atmISP(double);
    void set_vacISP(double);
    void set_escapeDV(double);
    void set_totalMass(double);
    void set_fuelMass(double);
    void set_fuelMass(std::vector<double>);
    
    double get_atmISP();
    double get_vacISP();
    double get_escapeDV();
    double get_totalMass();
    double get_fuelMass();
};

#endif
