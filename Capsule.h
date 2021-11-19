#ifndef CAPSULE_H
#define CAPSULE_H

#include <string>
#include <vector>
#include <iostream>

#include "network.h"


class Capsule 
{
private:
    std::string name;
    Network * satStorage = new Network();
    const int capacity = 60;
public:
    Capsule(std::string);
    ~Capsule();
    virtual void unloadCrew();
    virtual void unloadContents() = 0;
    void deployToNetwork(Network *);
    bool addToNetwork(StarlinkSatellite *);
    
    void dockToISS(Network *);

};

#endif