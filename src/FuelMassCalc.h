#ifndef FUELMASS_H
#define FUELMASS_H

#include <cmath>
#include <cstdlib>
#include "Physics.h"

class FuelMassCalculator : public Physics {
public:
			FuelMassCalculator();
	float	Calculate(int argc, char **argv);
};

#endif