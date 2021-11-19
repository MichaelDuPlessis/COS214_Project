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

ThrusterFactory::createVaccumeThruster() 
{
    return customThrustor(true,1,1); 
}

Thruster* ThrusterFactory::customThrustor(bool hascore, int decorated, int engines){
    Thruster* thrustor;
    
    if(hascore){
        thrustor = new FalconCore(true); 
    }
    else{
        thrustor =  new Merlin();
        if(engines <= decorated)  thrustor =  Vacuum(thuster, true);                     // add decorator 

        return thruster
    }

    for (int i = 0; i < engines; i++)
    {
        Thurster* engine = new Merlin();
        if(i <decorated)  engine = new Vacuum(engin, true);                     // add decorator 

        thrustor->addThruster(new Merlin());
    }
    
    return thruster
}
ThrusterFactory::~ThrusterFactory() 
{
    cout << "Thruster Factory Destroyed" << endl;
}


