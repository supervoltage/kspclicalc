#include "FuelMassCalc.h"

FuelMassCalculator::FuelMassCalculator() {
}

float FuelMassCalculator::Calculate(int argc, char **argv) {
	float	reqWetToDry		= exp (atof(argv[2]) / (g() * atof(argv[3])));
	int		nEngine			= atoi(argv[4]);
	float	massEngine		= atof(argv[5]);
	float	massPayload		= atof(argv[6]);
	float	fuelEmptyRatio	= atof(argv[7]);
	
	return ((reqWetToDry - 1)*((nEngine*massEngine) + massPayload)*fuelEmptyRatio) / (fuelEmptyRatio - reqWetToDry);
}