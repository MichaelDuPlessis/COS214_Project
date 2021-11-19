#include "StarlinkSatellite.h"
#include <iostream>

StarlinkSatellite::StarlinkSatellite(int id) : id(id) {} 

StarlinkSatellite::~StarlinkSatellite() {}

void StarlinkSatellite::communicateGround() 
{
    
}

void StarlinkSatellite::communicateSatellite() 
{
    
}

int StarlinkSatellite::getID() 
{
    return this->id;
}