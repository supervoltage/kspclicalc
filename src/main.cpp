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

// TODO: add operator<< overloads for use with ostream's
// TODO: make it easy to use from CLI
// TODO: merge with master branch
// TODO: make a branch for Android development, create an app as well

int main()
{
    TrueDV tdv;
    
    std::cout << tdv(305, 345, 1500, 4, 2) << "\n";
    
    return 0;
}
