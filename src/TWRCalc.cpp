#include "TWRCalc.h"

TWRCalculator::TWRCalculator() {
}

float TWRCalculator::Calculate(int argc, char **argv) {
	float totalThrust	= 0.0f;
	float totalMass 	= atof(argv[2]);
	
	for (int i = 3; i < argc; i++) {
		totalThrust += atof(argv[i]);
	}
	
	return totalThrust / (totalMass * g());
}