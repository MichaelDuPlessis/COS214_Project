#ifndef CAPSULE_H
#define CAPSULE_H

#include <string>
#include <vector>
#include <iostream>

#include 

class Capsule
{
private:

public:
    Capsule();
    ~Capsule();
    virtual void printCrew() = 0;
    // virtual void printSatellites() = 0;
    virtual void printCargo() = 0;
    virtual void addCargo() = 0;
    virtual void removeCargo(int) = 0;

};

#endif