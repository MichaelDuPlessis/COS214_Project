#include "rocketfactory.h"

RocketFactory::RocketFactory(StageFactory *sf, CapsuleFactory *cf){
    cout << "Rocket Facotry Created" << endl;
    StgFact = sf;
    CpslFact = cf;
    
}

Rocket* RocketFactory::buildFalconHeavy(){

}

Rocket* RocketFactory::buildFalcon9(){

}

RocketFactory::~RocketFactory(){    
    delete StgFact;
    delete CpslFact;

    cout << "Rocket Facotry Destroyed" << endl;
}
