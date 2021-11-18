#include "merlinfactory.h"
#include <iostream>

MerlinFactory::MerlinFactory()
{
    cout << "Merlin Factory Created" << endl;
}

Merlin* MerlinFactory::createMerlin() 
{
    return new Merlin();
}

MerlinFactory::~MerlinFactory() 
{
    cout << "Merlin Factory Destroyed" << endl;
}
