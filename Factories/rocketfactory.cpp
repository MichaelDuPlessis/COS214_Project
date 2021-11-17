#include "rocketfactory.h"

RocketFactory::RocketFactory(StageFactory *sf, CapsuleFactory *cf)
{
    StgFact = sf;
    CpslFact = cf;
}

Rocket *RocketFactory::buildFalconHeavy()
{
    Stage *s = StgFact->buildStage();
    Capsule *c = CpslFact->buildCapsule();

    return new Rocket(s,c);
}

Rocket *RocketFactory::buildFalcon9()
{
    Stage *s = StgFact->buildStage();
    Capsule *c = CpslFact->buildCapsule();

    Rocket *r = new Rocket();
    r->attachStage(s);
    r->attachCapsule(c);
    return r;
}

RocketFactory::~RocketFactory()
{
    delete StgFact;
    delete CpslFact;

}
