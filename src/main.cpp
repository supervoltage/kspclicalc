#include <cstdio>
#include <cstdlib>
#include <string>
#include "DeltaVCalc.h"
#include "TWRCalc.h"
#include "ISPCalc.h"
#include "TrueDVCalc.h"
#include "FuelMassCalc.h"

void printHelp(char **argv, bool details);

int main(int argc, char **argv) {
	if (argc == 1) {
		printHelp(argv, false);
		return 0;
	}
	
	std::string command = argv[1];
	if (command == "-dv" || command == "--deltav") {
		if (argc >= 5) {
			DeltaVCalculator dvCalc;
			float result = dvCalc.Calculate (argc, argv);
			printf("%f\n", result);
			return 0;
		}
		else {
			printf("Error: invalid syntax\n");
			printf("Δv syntax: -dv  [isp] [total mass] [fuel mass 1] [fuel mass 2] [fuel mass 3]...\n");
			return 0;
		}
	}
	if (command == "-twr" || command == "--thrust-to-weight") {
		if (argc >= 4) {
			TWRCalculator twrCalc;
			float result = twrCalc.Calculate (argc, argv);
			printf("%f\n", result);
			return 0;
		}
		else {
			printf("Error: invalid syntax\n");
			printf("TWR syntax: -twr [total mass] [thrust 1] [thrust 2] [thrust 3]...\n");
			return 0;
		}
	}
	if (command == "-isp" || command == "--specific-impulse") {
		if (argc >= 3 && ((argc-1) % 2) != 0) {
			IspCalculator ispCalc;
			float result = ispCalc.Calculate (argc, argv);
			printf("%f\n", result);
			return 0;
		}
		else {
			printf("Error: invalid syntax\n");
			printf("ISP syntax: -isp [thrust 1] [isp 1] [thrust 2] [isp 2]...\n");
			return 0;
		}
	}
	if (command == "-tdv" || command == "--true-deltav") {
		if (argc >= 6) {
			TrueDeltaVCalculator tdvCalc;
			float result = tdvCalc.Calculate (argc, argv);
			printf("%f\n", result);
			return 0;
		}
		else {
			printf("Error: invalid syntax\n");
			printf("True Δv syntax: -tdv [atmIsp] [vacIsp] [escapeDv] [total mass] [fuel mass 1] [fuel mass 2]...\n");
			return 0;
		}
	}
	if (command == "-cpu" || command == "--convert-propellant-units") {
		if (argc >= 3) {
			float result = 0;
			for (int i = 2; i < argc; i++) {
				result += atof(argv[i]) / 200;
			}
			printf("%f\n", result);
			return 0;
		}
		else {
			printf("Error: invalid syntax\n");
			printf("Conversion syntax: -cpu [propellant units]\n");
			return 0;
		}
	}
	if (command == "-fm" || command == "--fuel-mass") {
		if (argc == 8) {
			FuelMassCalculator fmCalc;
			float result = fmCalc.Calculate (argc, argv);
			printf("%f\n", result);
			return 0;
		}
		else {
			printf("Error: invalid syntax\n");
			printf("Fuel mass syntax: -fm [Δv] [isp] [numEngines] [massEngine] [massPayload] [fullEmptyRatio]\n");
			return 0;
		}
	}
	if (command == "-ts" || command == "--time-split") {
		if (argc == 4) {
			if (atoi(argv[3]) >= 60) {
				printf("Error: invalid number of seconds\n");
				return 0;
			}
			double wseconds = ((atof(argv[2])*60) + atof(argv[3])) / 120;
			double minutes = 0;
			double seconds = modf (wseconds, &minutes) * 60;
			
			printf("%.0fm%.1fs\n", minutes, seconds);
			return 0;
		}
		else if (argc == 3) {
			if (atoi(argv[2]) >= 60) {
				printf("Error: invalid number of seconds\n");
				return 0;
			}
			double seconds = atof(argv[2]) / 2;
			printf("%.1fs\n", seconds);
			return 0;
		}
		else {
			printf("Error: invalid syntax\n");
			printf("Time split syntax: -ts [min] [s]\n");
			return 0;
		}
	}
	if (command == "-h" || command == "--help") {
		printHelp(argv, true);
		return 0;
	}
	
	printf("Error: invalid option specified\n");
	return 0;
}

void printHelp(char **argv, bool details) {
	printf("Usage: %s [OPTION] [PARAMETERS]...\n", argv[0]);
	printf("Calculator tool for Kerbal Space Program.\n");
	printf("  -dv,  --deltav\t\t\tcalculate DeltaV\n");
	printf("  -twr, --thrust-to-weight\t\tcalculate thrust-to-weight ratio\n");
	printf("  -isp, --specific-impulse\t\tcalculate specific impulse\n");
	printf("  -tdv, --true-deltav\t\t\tcalculate true DeltaV\n");
	printf("  -cpu, --convert-propellant-units\tconvert fuel units to tons\n");
	printf("  -fm,  --fuel-mass\t\t\tcalculate fuel mass needed to meet Δv\n");
	printf("  -ts,  --time-split\t\t\tdivide the given time by 2\n");
	if (details == false) {
		printf("\nMore information available if \'-h\' or \'--help\' are specified.\n");
	}
	if (details == true) {
		printf("\nSyntaxes: \n");
		printf("  -dv  [isp] [total mass] [fuel mass 1] [fuel mass 2] [fuel mass 3]...\n");
		printf("  -twr [total mass] [thrust 1] [thrust 2] [thrust 3]...\n");
		printf("  -isp [thrust 1] [isp 1] [thrust 2] [isp 2]...\n");
		printf("  -tdv [atmIsp] [vacIsp] [escapeDv] [total mass] [fuel mass 1] [fuel mass 2]...\n");
		printf("  -cpu [fuel units 1] [fuel units 2] [fuel units 3]...\n");
		printf("  -fm  [Δv] [isp] [numEngines] [massEngine] [massPayload] [fullEmptyRatio]\n");
		printf("  -ts  [min] [s]\n");
		printf("\nIn this calculator, the term \"fuel\" relates to both liquid fuel and oxidizer.\n");
		printf("Specifying multiple fuel masses to \'-cpu\' will cause it to convert each fuel mass\n");
		printf("and then add all of them up.\n");
		printf("Specifying a single option will cause an error, and show the correct usage of the\noption.\n\n");
		printf("The units of measurement in this calculator are:\n");
		printf("  -for weight: tons              [t]\n");
		printf("  -for thrust: kiloNewtons       [kN]\n");
		printf("  -for isp:    seconds           [s]\n");
		printf("  -for Δv:     meters per second [m/s]\n");
		printf("  -for time:   minutes, seconds  [min], [s]\n");
	}
}