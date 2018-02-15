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

#include <stdexcept>

// TODO: make it easy to use from CLI
// TODO: merge with master branch
// TODO: make a branch for Android development, create an app as well


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

#include <map>

int main(int argc, char** argv)
{    
    // test pointer usage
    Calculator* cal = new FuelMass;
    std::vector<std::string> in_arg_list {"2000", "345", "1", "0.5", "3.45", "9"};
    cal->setargs(in_arg_list);
    std::cout << cal->calculate() << "\n";
    
    delete cal;
    
    CLI cli(argc, argv, "kspclicalc", "quick calculator for several rocketry formulas");
    
    cli.add_option("f", "functionette", true, true);
    cli.add_option("h", "help", false, false);
    cli.add_option("a", "about", false, false);
    cli.parse();
    
    /*
    std::vector<std::string> input;
    for(int i = 0; i < argc; ++i)
        input.push_back(argv[i]);
    
    input.erase(input.begin());
    
    std::vector<Option> opt_db;
    
    Option* opt = new Option("f", "functionette", true, true);
    opt_db.push_back(*opt);
    delete opt;
    
    opt = new Option("h", "help", false, false);
    opt_db.push_back(*opt);
    delete opt;
    
    opt = new Option("a", "about", false, false);
    opt_db.push_back(*opt);
    delete opt;
    
    std::map<std::string, std::string> results;

    for (std::vector<std::string>::size_type i = 0; i < input.size(); ++i)
    {
        bool match = false;
        for (const auto& db_arg : opt_db)
        {
            if (input[i] == db_arg.get_short_name() || input[i] == db_arg.get_long_name())
            {
                if (db_arg.is_positional())
                {
                    results[input[i]] = input[i+1];
                    match = true;
                    ++i;
                }
                else
                {
                    results[input[i]] = "true";
                    match = true;
                }
                break;
            }
            else continue;
        }
        if (match == false)
            std::cerr << "invalid argument: " << input[i] << "\n";
    }
    
    for (const auto& it : results)
    {
        std::cout << it.first << " " << it.second << "\n";
    }
    */
    
    return 0;
}
