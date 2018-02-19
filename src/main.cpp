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
#include "cli/CLI.hpp"

// TODO: find a way to sensibly derive TimeSplit from Calculator
// TODO: Option - modify short and long commands to not include hyphens automatically. Leave it up to the user whether short/long options should have hyphens or not.
// TODO: implement a way to specify "default options" in CLI
// TODO: implement automatic help printing which returns a stringstream, not writing directly to an ostream in CLI
// TODO: make it easy to use from CLI
// TODO: merge with master branch
// TODO: make a fork for Android development


/*I could resort to my previous "functionette" idea in which the end user would write a "function"
 * into the commandline after the program name:
 *      kspclicalc dv(345, 5, 2.5)
 * 
 * The above would calculate the required information for DeltaV and spit it out. That also means
 * we can put multiple functionettes inside of each other:
 *      kspclicalc dv(345, 5, cpu(88.58))
 * which would calculate cpu() first, replace the third argument with the output, then calculate the
 * dv() functionette.
 * 
 * Regex to search for a functionette: \w+\(.+\)
 * 
 * The functionette idea is still not compliant with GNU, but then again this program is not very
 * easy to write in a GNU compliant manner. It's not.. simple enough. It's not just a simple tool
 * like a calculator filled with buttons or simpler commands like "ls", "cd", "mv" etc.
 * 
 * Then again, "sed" is not a fully compliant GNU program as it makes use of string-based commands.
 * That makes me feel better about using the functionette idea.
*/

int main(int argc, char** argv)
{    
    /*
    // test pointer usage
    Calculator* cal = new FuelMass;
    std::vector<std::string> in_arg_list {"2000", "345", "1", "0.5", "3.45", "9"};
    cal->setargs(in_arg_list);
    std::cout << cal->calculate() << "\n";
    
    delete cal;
    */
    CLI cli(argc, argv, "kspclicalc", "quick calculator for several rocketry formulas");
    
    cli.add_option("functionette", "generic expression for invoking calculator functions", "f", "functionette", true, true);
    cli.add_option("help", "print helpful information about program", "h", "help", false, false);
    cli.add_option("about", "print information about the developer", "a", "about", false, false);
    cli.add_option("verbose", "flag indicating verbosity of program", "v", "verbose", false, true);
    cli.parse();
    
    std::cout << cli.get_results().size() << "\n";
    
    for (const auto& it : cli.get_results())
    {
        std::cout << it.get_name() << " " << it.get_result<std::string>() << "\n";
    }
    
    return 0;
}
