#include "thrusterfactory.h"
#include <iostream>

ThrusterFactory::ThrusterFactory()
{
    cout << "Thruster Factory Created" << endl;
}

Thruster* ThrusterFactory::createCoreThruster() 
{
    return customThrustor(true,0,9);
}

Thruster* ThrusterFactory::createVaccumeThruster() 
{
    return customThrustor(true,1,1); 
}

Thruster* ThrusterFactory::customThrustor(bool hascore, int decorated, int engines){
    Thruster* thruster;
    
    if(hascore){
        thruster = new FalconCore(true); 
    }
    else{
        thruster =  new Merlin();
        if(engines <= decorated)  thruster = new Vacuum(thruster, true);                     // add decorator 

        return thruster;
    }

    for (int i = 0; i < engines; i++)
    {
        Thruster* engine = new Merlin();
        if(i <decorated)  engine = new Vacuum(engine, true);                     // add decorator 

        thruster->addThruster(new Merlin());
    }
    
    return thruster;
}
ThrusterFactory::~ThrusterFactory() 
{
    cout << "Thruster Factory Destroyed" << endl;
}


