#include <cstdio>
#include <cstdlib>
#include <string>
#include "DeltaVCalc.h"
#include "TWRCalc.h"
#include "ISPCalc.h"

void printHelp(char **argv);

int main(int argc, char **argv) {
	if (argc == 1) {
		printHelp(argv);
		return 0;
	}
	
	std::string command = argv[1];
	if (command == "-dv" && argc >= 5) {
		DeltaVCalculator dvCalc;
		float result = dvCalc.Calculate (argc, argv);
		printf("%f\n", result);
		return 0;
	}
	if (command == "-twr" && argc >= 4) {
		TWRCalculator twrCalc;
		float result = twrCalc.Calculate (argc, argv);
		printf("%f\n", result);
		return 0;
	}
	if (command == "-isp" && argc >= 3 && ((argc-1) % 2) != 0 ) {
		IspCalculator ispCalc;
		float result = ispCalc.Calculate (argc, argv);
		printf("%f\n", result);
		return 0;
	}
	if (command == "-h" || command == "--help") {
		printHelp(argv);
		return 0;
	}
	
	printf("Error: invalid syntax\n");
	return 0;
}

void printHelp(char **argv) {
	printf("Usage: %s [OPTION]... [PARAMETERS]...\n", argv[0]);
	printf("Calculator tool for Kerbal Space Program.\n");
	printf("Calculates DeltaV, thrust-to-weight ratio, and specific impulse.\n\n");
	printf("  -dv\t\t\tcalculate DeltaV\n");
	printf("  -twr\t\t\tcalculate thrust-to-weight ratio\n");
	printf("  -isp\t\t\tcalculate specific impulse\n\n");
	printf("Syntaxes: \n");
	printf("  -dv  [isp] [total mass] [fuel mass 1] [fuel mass 2] [fuel mass 3]...\n");
	printf("  -twr [total mass] [thrust 1] [thrust 2] [thrust 3]...\n");
	printf("  -isp [thrust 1] [isp 1] [thrust 2] [isp 2]...\n");
}