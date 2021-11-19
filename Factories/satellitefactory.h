#ifndef SATELLITEFACTORY_H
#define SATELLITEFACTORY_H

#include "../StarlinkSatellite.h"

using namespace std;

class SatelliteFactory
{
public:
    SatelliteFactory();

    StarlinkSatellite* createSatellite();

    ~SatelliteFactory();
};



#endif