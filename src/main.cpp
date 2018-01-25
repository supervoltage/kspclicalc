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

// TODO: provide ways of executing input checking, throw runtime errors if something's invalid
// TODO: turn all classes into functors. take the input args via the () operator and calculate immediately.
// TODO: make it easy to use from CLI
// TODO: port to Android, create an app as well

int main()
{
    FuelMass fm;
    
    fm.setargs(1300, 320, 1, 1.5, 7.45, 9);
    fm.calculate();
    
    std::cout << fm.getResult() << "\n";
    std::cout << exp(1300 / (320*9.807)) << "\n";
    
    return 0;
}
