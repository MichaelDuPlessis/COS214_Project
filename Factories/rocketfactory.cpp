#include "rocketfactory.h"
#include "../Falcon9Strategy.h"
#include "../FalconHeavyStrategy.h"
#include "../StageObserver.h"

RocketFactory::RocketFactory() 
{

    StgFact = new StageFactory(new ThrusterFactory());
    CDFact = new CD_CapsuleFactory();
    CFact = new C_CapsuleFactory();

    // cout << "Rocket Facotry Created" << endl;
}

RocketFactory::RocketFactory(StageFactory *sf, C_CapsuleFactory *cd, CD_CapsuleFactory *d){
    // cout << "Rocket Facotry Created" << endl;

    if(sf==NULL) StgFact = new StageFactory(new ThrusterFactory());
    else StgFact = sf;
    if(cd==NULL) CDFact = new CD_CapsuleFactory();
    else CDFact = cd;
    if(d==NULL) CFact = new C_CapsuleFactory();
    else CFact = d;
    
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

    this->addObservers(stages);

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

    this->addObservers(stages);

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

    if(StgFact != NULL) delete StgFact;
    if(CDFact != NULL) delete CDFact;
    if(CFact != NULL) delete CFact ;

    // cout << "Rocket Facotry Destroyed" << endl;
}

void RocketFactory::addObservers(vector<Stage*> stages)
{
    vector<StageObserver*> obs;

    for (std::vector<Stage*>::iterator itr = stages.begin(); itr != stages.end(); itr++)
        obs.push_back(new StageObserver(*itr));

    for (std::vector<StageObserver*>::iterator itr1 = obs.begin(); itr1 != obs.end(); itr1++)
        for (std::vector<Stage*>::iterator itr2 = stages.begin(); itr2 != stages.end(); itr2++)
            (*itr2)->attach(*itr1);
}