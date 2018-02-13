// kspclicalc2 - code entirely rewritten to account for silly early programming

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "calc/DeltaV.hpp"
#include "calc/TWR.hpp"
#include "calc/TimeSplit.hpp"
#include "calc/ISP.hpp"
#include "calc/TrueDV.hpp"
#include "calc/FuelMass.hpp"
#include "cli/Option.hpp"

// TODO: make it easy to use from CLI
// TODO: merge with master branch
// TODO: make a branch for Android development, create an app as well

int main(int argc, char** argv)
{    
    // test pointer usage
    Calculator* cal = new FuelMass;
    std::vector<std::string> in_arg_list {"2000", "345", "1", "0.5", "3.45", "9"};
    cal->setargs(in_arg_list);
    std::cout << cal->calculate() << "\n";
    
    delete cal;
    
    Option opt("dv", "--delta-v");
    opt.store("true");
    
    std::cout << opt.get_short_name() << " " << opt.get_long_name() << "\n";
    
    std::cout << opt.get_result<std::string>() << "\n";
    
    return 0;
}
