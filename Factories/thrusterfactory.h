#ifndef THRUSTERFACTORY_H
#define THRUSTERFACTORY_H

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
    ~ThrusterFactory();
};

#endif // MERLINFACTORY_H
