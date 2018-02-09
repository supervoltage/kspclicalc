// kspclicalc2 - code entirely rewritten to account for silly early programming

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "cli/CLI.hpp"
#include "calc/DeltaV.hpp"
#include "calc/TWR.hpp"
#include "calc/TimeSplit.hpp"
#include "calc/ISP.hpp"
#include "calc/TrueDV.hpp"
#include "calc/FuelMass.hpp"

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
    Calculator* cal = new FuelMass;
    std::vector<std::string> in_arg_list {"2000", "345", "1", "0.5", "3.45", "9"};
    cal->setargs(in_arg_list);
    std::cout << cal->calculate() << "\n";
    
    delete cal;
    
    return 0;
}

void setupCommands(CLI& cli)
{
    // we never use more memory than the item being worked on
    Command* com;
    std::vector<argument> arg_list;
    
    // set up the DeltaV command
    arg_list.push_back(std::pair<std::string, std::string>("isp", "specific impulse of engines"));
    arg_list.push_back(std::pair<std::string, std::string>("totalMass", "total mass of stage"));
    arg_list.push_back(std::pair<std::string, std::string>("fuelMass", "mass of all fuel in stage, including oxidizer"));
    com = new Command("-dv", "calculates the DeltaV a craft/stage can perform", 3, 3, arg_list);
    cli.register_command(*com);
    
    // clean up to prepare for another command
    delete com;
    arg_list.clear();
    
    // set up the FuelMass command
    arg_list.push_back(std::pair<std::string, std::string>("deltaV", "deltaV requirement for craft"));
    arg_list.push_back(std::pair<std::string, std::string>("isp", "isp of engine or combined engines"));
    arg_list.push_back(std::pair<std::string, std::string>("nEngines", "number of engines"));
    arg_list.push_back(std::pair<std::string, std::string>("massEngine", "mass of an engine"));
    arg_list.push_back(std::pair<std::string, std::string>("massPayload", "mass of payload to carry"));
    arg_list.push_back(std::pair<std::string, std::string>("fullEmptyRatio", "Full-to-Empty ratio of a fuel tank: FullMass / EmptyMass"));
    com = new Command("-fm", "calculates the amount of fuel mass required to meet an arbitrary DeltaV amount", 6, 6, arg_list);
    cli.register_command(*com);
    
    delete com;
    arg_list.clear();
}
