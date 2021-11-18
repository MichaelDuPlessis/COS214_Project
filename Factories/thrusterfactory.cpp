#include "thrusterfactory.h"
#include <iostream>

ThrusterFactory::ThrusterFactory()
{
    cout << "Thruster Factory Created" << endl;
}

Thruster* ThrusterFactory::createCoreThruster() 
{
    
}


Thruster* ThrusterFactory::createCVaccumeThruster() 
{
    return new Vaccuum(new Merlin());
}

ThrusterFactory::~ThrusterFactory() 
{
    cout << "Thruster Factory Destroyed" << endl;
}


