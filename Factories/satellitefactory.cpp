#include "satellitefactory.h"
#include <iostream>

SatelliteFactory::SatelliteFactory() 
{
    cout << "Satellite Factory Created" << endl;
}

Satellite* SatelliteFactory::createSatellite() 
{
    return new Satellite();
}


SatelliteFactory::~SatelliteFactory() 
{
    cout << "Satellite Factory Destroyed" << endl;
}
