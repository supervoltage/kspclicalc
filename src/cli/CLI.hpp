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
    std::vector<std::string> m_opt_defaults; // default options/flags, as defined by user
    std::vector<std::string> m_user_input;  // input, typically argc+argv
    std::vector<std::pair<std::string, std::string> > m_results;    // vector to store results in
    
    const std::string m_prog_name;      // name of program
    const std::string m_prog_desc;      // description of program
    std::string m_exec_name;            // name of executable
protected:
    std::vector<std::string> separate_opts(const std::vector<std::string>&);
public:
    CLI(int argc, char** argv, std::string prog_name, std::string prog_desc);
    void add_option(std::string name, std::string short_name, std::string long_name,
                    bool positional=false, bool repeatable=false);
    
    std::vector<std::pair<std::string, std::string> > get_results() const;
    
    // operator overload for returning the results of individual options, returns an empty string
    // on no match
    std::string operator[] (const std::string&) const;
    int parse();
};

#endif
