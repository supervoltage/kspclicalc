#include "ISPCalc.h"
#include <cstdio>

IspCalculator::IspCalculator() {
}

float IspCalculator::Calculate(int argc, char **argv) {
	float thrustSum = 0.0f;
	for (int i = 2; i < argc; i+=2) {
		thrustSum += atof(argv[i]);
	}
	
	float ratioSum = 0.0f;
	for (int i = 2; i <= argc-1; i+=2) {
		float ratio = atof(argv[i]) / atof(argv[i+1]);
		ratioSum += ratio;
	}
	
	return thrustSum / ratioSum;
}