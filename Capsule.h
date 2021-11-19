#ifndef CAPSULE_H
#define CAPSULE_H

#include <string>
#include <vector>
#include <iostream>

#include "network.h"


class Capsule 
{
private:
    Network * satStorage;
    const int capacity = 60;
public:
    Capsule();
    ~Capsule();
    virtual void unloadCrew();
    virtual void unloadContents() = 0;
    void deployToNetwork(Network *);
    bool addToNetwork(StarlinkSatellite *);
    
    void dockToISS(Network *);

};

#endif