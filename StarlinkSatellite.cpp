#include "StarlinkSatellite.h"

int StarlinkSatellite::id = 0;

StarlinkSatellite::StarlinkSatellite()
{
    id = ++id;
}

StarlinkSatellite::StarlinkSatellite() {}

StarlinkSatellite::~StarlinkSatellite() {}

void StarlinkSatellite::communicateGround() 
{
    // std::cout 
}

void StarlinkSatellite::communicateSatellite() {}

int StarlinkSatellite::getID() 
{
    return id;
}