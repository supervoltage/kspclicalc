#ifndef DV_H
#define DV_H

#include <cmath>
#include <cstdlib>
#include "Physics.h"

class DeltaVCalculator : public Physics {
public:
				DeltaVCalculator();
	float		Calculate(int argc, char **argv);
};

#endif