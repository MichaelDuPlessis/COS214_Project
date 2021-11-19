#ifndef ROCKETFACTORY_H
#define ROCKETFACTORY_H

#include "stagefactory.h"
#include "capsulefactory.h"

//#include "capsule.h"
//#include "stage.h"



using namespace std;

class RocketFactory
{

private:
    StageFactory* StgFact;
    CapsuleFactory* CpslFact;

public:
    RocketFactory(StageFactory* sf,CapsuleFactory* cf );
    Rocket* buildFalconHeavy();
    Rocket* buildFalcon9();
    ~RocketFactory();
};

#endif // ROCKETFACTORY_H

