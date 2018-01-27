// kspclicalc2 - code entirely rewritten to account for silly early programming

#include <iostream>
#include <iomanip>
#include <vector>
#include "DeltaV.hpp"
#include "TWR.hpp"
#include "TimeSplit.hpp"
#include "ISP.hpp"
#include "TrueDV.hpp"
#include "FuelMass.hpp"

// TODO: turn all classes into functors. take the input args via the () operator and calculate immediately.
// TODO: make it easy to use from CLI
// TODO: make a branch for Android development, create an app as well

int main()
{
    DeltaV dv;
    
    dv.setargs(2, 345, 4);
    
    std::cout << dv.calculate() << "\n";
    
    return 0;
}
