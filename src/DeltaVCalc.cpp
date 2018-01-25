#include "DeltaVCalc.h"

DeltaVCalculator::DeltaVCalculator() {
}

float DeltaVCalculator::Calculate(int argc, char **argv) {
	float fuelMass = 0.0f;

	for (int i = 4; i < argc; i++) {
		fuelMass += atof(argv[i]);
	}
	const float isp			= atof(argv[2]);
	const float totalMass	= atof(argv[3]);

	return log(totalMass / (totalMass - fuelMass)) * isp * g();
}

float DeltaVCalculator::CalculateInternal(float isp, float totalMass, float fuelMass) {
	return log(totalMass / (totalMass - fuelMass)) * isp * g();
}
