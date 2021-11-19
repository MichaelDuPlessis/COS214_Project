#ifndef CAPSULEFACTORY_H
#define CAPSULEFACTORY_H

#include <vector>
#include <iostream>

#include "../Capsule.h"
#include "../Dragon.h"
#include "../CrewDragon.h"

using namespace std;


class Satellite;

class CapsuleFactory{
public:
    CapsuleFactory();
    virtual Capsule* buildCapsule() = 0;

    virtual ~CapsuleFactory();
};


class CD_CapsuleFactory : public CapsuleFactory
{
private:
    /* data */
public:
    CD_CapsuleFactory();
    Capsule* buildCapsule();

    ~CD_CapsuleFactory();
};

class C_CapsuleFactory : public CapsuleFactory{
private:
    /* data */
public:
    C_CapsuleFactory();
    Capsule* buildCapsule();

    ~C_CapsuleFactory();
};


#endif // CAPSULEFACTORY_H
