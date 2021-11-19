#ifndef CAPSULE_H
#define CAPSULE_H

#include <string>
#include <vector>
#include <iostream>

#include "network.h"


class Capsule 
{
public:
    Capsule();
    ~Capsule();
    virtual void printCrew() = 0;
    virtual void dockToISS() = 0;
    virtual Capsule * clone() = 0;
    virtual void deployNetwork() = 0;
};

#endif