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

int main(int argc, char** argv)
{
    std::vector<std::string> input;
    for(int i = 0; i < argc; ++i)
        input.push_back(argv[i]);
    
    CLI cli(input);
    
    return 0;
}
