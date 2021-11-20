#include "rocketfactory.h"
#include "../Falcon9Strategy.h"
#include "../FalconHeavyStrategy.h"

RocketFactory::RocketFactory() 
{

    StgFact = new StageFactory(new ThrusterFactory());
    CDFact = new CD_CapsuleFactory();
    CFact = new C_CapsuleFactory();

    cout << "Rocket Facotry Created" << endl;
}

RocketFactory::RocketFactory(StageFactory *sf, C_CapsuleFactory *cd, CD_CapsuleFactory *d){
    cout << "Rocket Facotry Created" << endl;
    StgFact = sf;
    CDFact = cd;
    CFact = d;
    
}
//====================================================================================================================//

Rocket* RocketFactory::buildFalconHeavy(string name, bool crewdragon = true){
    vector<Stage*> stages;
    Capsule* c = builldCapsule(crewdragon);

////// create first stage ///////////////////////////////////

    Stage* s = StgFact->createLargeStage(false);        // -> false because its a falcon heavy
    stages.push_back(s);

////// create second stage //////////////////////////////////
    s = StgFact->createSmallStage();
    stages.push_back(s);

    return new Rocket(new FalconHeavyStrategy(), c, stages, name);

}
//====================================================================================================================//

Rocket* RocketFactory::buildFalcon9(string name, bool crewdragon = true){

    vector<Stage*> stages;
    Capsule* c = builldCapsule(crewdragon);

////// create first stage ///////////////////////////////////

    Stage* s = StgFact->createLargeStage(true);        // -> true because its a falcon 9
    stages.push_back(s);

////// create second stage //////////////////////////////////
    s = StgFact->createSmallStage();
    stages.push_back(s);

    return new Rocket(new Falcon9Strategy(), c, stages, name);
}
//====================================================================================================================//

Capsule* RocketFactory::builldCapsule(bool crewdragon) 
{
    Capsule* c;
    if(crewdragon) c = CDFact->buildCapsule();
    else c = CFact->buildCapsule();

    return c;
}

RocketFactory::~RocketFactory(){    
    delete StgFact;
    delete CDFact;
    delete CFact ;

    cout << "Rocket Facotry Destroyed" << endl;
}


