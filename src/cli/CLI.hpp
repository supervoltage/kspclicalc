#ifndef CLI_H
#define CLI_H

#include "Option.hpp"

// REWRITE WARNING
/*
 * I think I should completely rewrite the CLI parsing lib as I'm overcomplicating things again.
 * Standard GNU argument parsing doesn't take several positional arguments for a switch, it only
 * takes one. Therefore I have to write a more standard way of parsing arguments of the following
 * types:
 *      --longargname arg
 *      --longargname=arg
 *      -a
 *      -ab
 *      -abl arg
 * 
 * That means that the old way of parsing arguments for the internal DeltaV, ISP, TWR, FuelMass and
 * other calculators is not compliant with standard GNU. So I should rethink how that'll be parsed.
*/

class CLI
{
private:
    std::vector<Option> m_opt_db;   // options to look out for, as defined by user
    std::vector<Option> m_opt_defaults; // default options/flags, as defined by user
public:
};

#endif
