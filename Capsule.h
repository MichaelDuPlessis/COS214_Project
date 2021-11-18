#ifndef CAPSULE_H
#define CAPSULE_H

#include <string>
#include <vector>
#include <iostream>


class Capsule // : public aggregate
{
private:

public:
    Capsule();
    ~Capsule();
    virtual void printCrew() = 0;
    // virtual void printSatellites() = 0;
    virtual void dockToISS() = 0;

};

#endif