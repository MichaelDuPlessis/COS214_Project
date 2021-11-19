#ifndef THRUSTERFACTORY_H
#define THRUSTERFACTORY_H

#include <iostream>

using namespace std;

#include "../thruster.h"
#include "../FalconCore.h"
#include "../merlin.h"
#include "../vacuum.h"

class ThrusterFactory
{
public:
    ThrusterFactory();
    Thruster* createCoreThruster();
    Thruster* createVaccumeThruster();

    Thruster* customThrustor(bool hascore, int decorated, int engines);
    ~ThrusterFactory();
};

#endif // MERLINFACTORY_H
