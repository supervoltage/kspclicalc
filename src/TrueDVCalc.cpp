#include "TrueDVCalc.h"

TrueDeltaVCalculator::TrueDeltaVCalculator() {
}

float TrueDeltaVCalculator::Calculate(int argc, char **argv) {
	DeltaVCalculator dvCalc;
										//prepare variables for calculations
	float atmIsp	= atof(argv[2]);
	float vacIsp	= atof(argv[3]);
	float escapeDv	= atof(argv[4]);
	float totalMass = atof(argv[5]);
	
	float fuelMass = 0.0f;
	
	for (int i = 6; i < argc; i++) {
		fuelMass += atof(argv[i]);
	}
										//do the calculations
	float atmDv = dvCalc.CalculateInternal(atmIsp, totalMass, fuelMass);
	float vacDv = dvCalc.CalculateInternal(vacIsp, totalMass, fuelMass);
	
	return (((atmDv - escapeDv) * vacDv) / atmDv) + escapeDv;
}