#ifndef CLI_H
#define CLI_H

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
 * 
 * I could resort to my previous "functionette" idea in which the end user would write a "function"
 * into the commandline after the program name:
 *      kspclicalc dv(345, 5, 2.5)
 * 
 * The above would calculate the required information for DeltaV and spit it out. That also means
 * we can put multiple functionettes inside of each other:
 *      kspclicalc dv(345, 5, cpu(88.58))
 * which would calculate cpu() first, replace the third argument with the output, then calculate the
 * dv() functionette.
 * 
 * The functionette idea is still not compliant with GNU, but then again this program is not very
 * easy to write in a GNU compliant manner. It's not.. simple enough. It's not just a simple tool
 * like a calculator filled with buttons or simpler commands like "ls", "cd", "mv" etc.
 * 
 * Then again, "sed" is not a fully compliant GNU program as it makes use of string-based commands.
 * That makes me feel better about using the functionette idea.
*/

class CLI
{
private:
public:
};

#endif
