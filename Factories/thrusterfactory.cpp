#include "thrusterfactory.h"
#include <iostream>

ThrusterFactory::ThrusterFactory()
{
    cout << "Thruster Factory Created" << endl;
}

Thruster* ThrusterFactory::createCoreThruster() 
{
    FalconCore* fc = new FalconCore(true);  // this core will delete its engines

    for (int i = 0; i < 9; i++)
    {
        fc->addThruster(new Merlin());
    }
    
}


Thruster* ThrusterFactory::createVaccumeThruster() 
{
    return new Vaccuum(new Merlin(), true); // this vaccum whats attached to it
}

ThrusterFactory::~ThrusterFactory() 
{
    cout << "Thruster Factory Destroyed" << endl;
}


