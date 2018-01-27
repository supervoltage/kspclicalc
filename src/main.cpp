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
// TODO: merge with master branch
// TODO: make a branch for Android development, create an app as well

int main()
{
    FuelMass fm;
    
    /*
    set_deltaV          (new_deltaV);
    set_isp             (new_isp);
    set_nEngines        (new_nEngines);
    set_massEngine      (new_massEngine);
    set_massPayload     (new_massPayload);
    set_fullEmptyRatio  (new_fullEmptyRatio);
    */
    
    std::cout << fm(2000, 345, 1, 0.5, 5, 9) << "\n";
    
    return 0;
}
