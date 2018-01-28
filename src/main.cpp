// kspclicalc2 - code entirely rewritten to account for silly early programming

#include <iostream>
#include <iomanip>
#include <vector>
#include "calc/DeltaV.hpp"
#include "calc/TWR.hpp"
#include "calc/TimeSplit.hpp"
#include "calc/ISP.hpp"
#include "calc/TrueDV.hpp"
#include "calc/FuelMass.hpp"

// TODO: make it easy to use from CLI
// TODO: merge with master branch
// TODO: make a branch for Android development, create an app as well

int main()
{
    TrueDV tdv;
    
    std::cout << tdv(305, 345, 1500, 4, 2) << "\n";
    
    return 0;
}
