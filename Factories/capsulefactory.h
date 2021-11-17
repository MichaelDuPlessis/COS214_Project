#ifndef CAPSULEFACTORY_H
#define CAPSULEFACTORY_H

#include "capsule.h"
//this will actually be a abstract factory

class CapsuleFactory
{
public:
    CapsuleFactory();
    virtual Capsule* buildCapsule() = 0;

    ~CapsuleFactory();
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

class C_CapsuleFactory : public CapsuleFactory
{
private:
    /* data */
public:
    C_CapsuleFactory();
    Capsule* buildCapsule();

    ~C_CapsuleFactory();
};


#endif // CAPSULEFACTORY_H
