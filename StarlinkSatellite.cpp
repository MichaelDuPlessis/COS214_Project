#include "StarlinkSatellite.h"
#include "MasterNetwork.h"
#include <iostream>

StarlinkSatellite::StarlinkSatellite()
{
    this->id = MasterNetwork::instance()->getID();
} 

StarlinkSatellite::~StarlinkSatellite() {}

void StarlinkSatellite::communicateGround() 
{
    std::cout << "Satellite-" << this->id << " is communicating with the ground.\n";
}

void StarlinkSatellite::communicateSatellite() 
{
   std::cout << "Satellite-" << this->id << " is communicating with other satellites\n";
}

int StarlinkSatellite::getID() 
{
    return this->id;
}