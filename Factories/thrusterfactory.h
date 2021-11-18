#ifndef THRUSTERFACTORY_H
#define THRUSTERFACTORY_H

using namespace std;

#include "../thruster.h"
#include "../falcon_core.h"
#include "../merlin.h"
#include "../vacuum.h"

class ThrusterFactory
{
public:
    ThrusterFactory();
    Thruster* createCoreThruster();
    Thruster* createCVaccumeThruster();
    ~ThrusterFactory();
};

#endif // MERLINFACTORY_H