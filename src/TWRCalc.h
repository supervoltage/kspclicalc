#ifndef TWRC_H
#define TWRC_H

#include <cstdlib>
#include "Physics.h"

class TWRCalculator : public Physics {
public:
			TWRCalculator();
	float	Calculate(int argc, char **argv);
};

#endif