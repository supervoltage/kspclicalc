#ifndef ISP_H
#define ISP_H

#include "Calculator.hpp"
#include <vector>
#include <ostream>

// we define an engine as a pair of parameters: ISP (s) and thrust (kN)
typedef double in_isp;
typedef double in_thrust;
typedef std::pair<in_isp, in_thrust> engine;

class ISP : public Calculator
{
private:
    std::vector<engine> engines;
public:
    ISP();
    ISP(std::vector<engine>);
    ISP(engine);
    ISP(double, double);
    
    virtual double calculate();
    virtual void clearall();
    virtual void clearresult();
    virtual void clearargs();
    
    const std::vector<engine>& get_engines();
    
    void set_engines(std::vector<engine>);  // set whole list
    void insert_engine(engine);             // insert one into list
    void insert_engine(double, double);     // insert one into list with direct values
    
    double operator()(std::vector<engine>);
    double operator()(engine);
    double operator()(double, double);
};

std::ostream& operator<< (std::ostream& os, const ISP& isp);

#endif
