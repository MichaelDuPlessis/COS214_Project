#include "capsulefactory.h"


////////////////////////////////////////////////////////////////////////////////////
CapsuleFactory::CapsuleFactory()
{

}

CapsuleFactory::~CapsuleFactory() {}

////////////////////////////////////////////////////////////////////////////////////////////

CD_CapsuleFactory::CD_CapsuleFactory() 
{
    cout << "Crew Dragon Capsule Factory Created" << endl;
}

Capsule* CD_CapsuleFactory::buildCapsule() 
{
    return new CrewDragon();
}

CD_CapsuleFactory::~CD_CapsuleFactory() 
{
    cout << "Crew Dragon Capsule Factory Destroyed" << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////

C_CapsuleFactory::C_CapsuleFactory() 
{
    cout << "Crew Capsule Factory Created" << endl;
}

Capsule* C_CapsuleFactory::buildCapsule() 
{
    return new CrewDragon();
}

C_CapsuleFactory::~C_CapsuleFactory() 
{
    cout << "Crew Capsule Factory Destroyed" << endl;
}

