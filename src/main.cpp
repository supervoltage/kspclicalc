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

// TODO: make it easy to use from CLI
//  So.. CLI.. uuuhhh......
//  interaction with the program will be done via commands of the form -dv, -ts,
//  -twr etc. These are all followed by either numerical values or strings,
//  depending on the kind of information the command will take.
//
//  Each command will have a short version (-dv) and long version (--deltav).
//  Commands will always begin with at least one hyphen ( - ).
//
//  So. The CLI will take the vector of inputs (including program name) and
//  execute several functions out of it, which eventually make use of the
//  classes within the calc directory.
//  It will extract the commands and their arguments from within the vector,
//  keeping the rest in. Then it executes those functions if it meets the
//  minimum argument count for each command.
//
//  The program won't stop if a command fails - it will throw a warning then
//  carry on.

// TODO: merge with master branch
// TODO: make a branch for Android development, create an app as well

// putting all CLI command definitions inside a function to not pollute the main function so much
void setupCommands(CLI& cli);

int main(int argc, char** argv)
{
    // get all the input from the commandline and put it in the CLI class
    std::vector<std::string> input;
    for(int i = 0; i < argc; ++i)
        input.push_back(argv[i]);
    CLI cli(input);
    setupCommands(cli);

    std::cout << "Program name: " << cli.get_prog_name() << "\n";
    
    cli.printCapabilities(std::cout) << "\n";
    
    // test pointer usage
    Calculator* cal = new DeltaV;
    std::vector<std::string> in_arg_list {"345", "10", "5"};
    cal->setargs(in_arg_list);
    std::cout << cal->calculate() << "\n";
    
    delete cal;
    
    return 0;
}

void setupCommands(CLI& cli)
{
    std::vector<argument> arg_list;
    arg_list.push_back(std::pair<std::string, std::string>("isp", "specific impulse of engines"));
    arg_list.push_back(std::pair<std::string, std::string>("totalmass", "total mass of stage"));
    arg_list.push_back(std::pair<std::string, std::string>("fuelmass", "mass of all fuel in stage, including oxidizer"));
    Command com("-dv", 3, 3, arg_list);
    cli.register_command(com);
}
