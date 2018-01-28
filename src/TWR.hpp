#ifndef TWR_H
#define TWR_H

#include "phys.hpp"
#include "Calculator.hpp"
#include <vector>

class TWR : public Calculator
{
private:
    double totalThrust;
    double totalMass;
public:
    TWR();
    TWR(double new_totalThrust, double new_totalMass);
    
    double get_totalThrust();
    double get_totalMass();
    
    void set_totalThrust(double);
    void set_totalThrust(std::vector<double>);
    void set_totalMass(double);
    
    void setargs(double new_totalThrust, double new_totalMass);
    
    virtual double calculate();
    virtual void clearall();
    virtual void clearresult();
    virtual void clearargs();
    
    double operator()(double new_totalThrust, double new_totalMass);
};

#endif
