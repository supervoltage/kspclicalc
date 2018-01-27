#ifndef DELTAV_H
#define DELTAV_H

#include <vector>
#include <cmath>
#include "Calculator.hpp"

class DeltaV : public Calculator
{
private:
    double  fuelMass;
    double  isp;
    double  totalMass;
public:
    DeltaV();
    DeltaV(double new_fuelMass, double new_isp, double new_totalMass);
    double get_fuelMass();
    double get_isp();
    double get_totalMass();
    
    void set_fuelMass(double);
    void set_fuelMass(std::vector<double>);
    void set_isp(double);
    void set_totalMass(double);
    
    void setargs(double new_fuelMass, double new_isp, double new_totalMass);
    
    virtual double calculate();
    virtual void clearall();
    virtual void clearresult();
    virtual void clearargs();
    
    double operator()(double new_fuelMass, double new_isp, double new_totalMass);
};

#endif
