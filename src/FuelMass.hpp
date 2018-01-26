#ifndef FUELMASS_H
#define FUELMASS_H

#include "Calculator.hpp"

class FuelMass : public Calculator
{
private:
    double deltaV;
    double isp;
    int nEngines;
    double massEngine;
    double massPayload;
    double fullEmptyRatio;
public:
    FuelMass();
    FuelMass(double new_deltaV, double new_isp, int new_nEngines,
             double new_massEngine, double new_massPayload,
             double new_fullEmptyRatio);
    virtual double calculate();
    virtual void clearall();
    virtual void clearresult();
    virtual void clearargs();
    
    void setargs(double new_deltaV, double new_isp, int new_nEngines,
                 double new_massEngine, double new_massPayload,
                 double new_fullEmptyRatio);
    
    void set_deltaV(double);
    void set_isp(double);
    void set_nEngines(int);
    void set_massEngine(double);
    void set_massPayload(double);
    void set_fullEmptyRatio(double);
    
    double get_deltaV();
    double get_isp();
    int get_nEngines();
    double get_massEngine();
    double get_massPayload();
    double get_fullEmptyRatio();
};

#endif
