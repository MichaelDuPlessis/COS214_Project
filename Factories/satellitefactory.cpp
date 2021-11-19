#include "satellitefactory.h"
#include <iostream>

SatelliteFactory::SatelliteFactory() 
{
    cout << "Satellite Factory Created" << endl;
}

StarlinkSatellite* SatelliteFactory::createSatellite() 
{
    return new StarlinkSatellite();
}


SatelliteFactory::~SatelliteFactory() 
{
    cout << "Satellite Factory Destroyed" << endl;
}
