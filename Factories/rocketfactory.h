#ifndef ROCKETFACTORY_H
#define ROCKETFACTORY_H

#include "stagefactory.h"
#include "capsulefactory.h"

#include "../Rocket.h"
#include "../Stage.h"
#include "../Capsule.h"
#include "../LLStrategy.h"

#include <vector>
#include <iostream>

using namespace std;

class RocketFactory
{

private:
    StageFactory* StgFact;
    CapsuleFactory* CFact;
    CapsuleFactory* CDFact;

public:
    RocketFactory();
    RocketFactory(StageFactory *sf, C_CapsuleFactory *cd, CD_CapsuleFactory *d);
    Rocket* buildFalconHeavy(LLStrategy* s, bool crewdragon = true);
    Rocket* buildFalcon9(LLStrategy* s, bool crewdragon = true);

    Capsule* builldCapsule(bool crewdragon = true);
    ~RocketFactory();
};

#endif // ROCKETFACTORY_H

