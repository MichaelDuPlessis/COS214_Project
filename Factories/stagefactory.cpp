#include "stagefactory.h"


StageFactory::StageFactory()
{
    cout << "Created Stage Factory" << endl;
}

StageFactory::~StageFactory()
{
    delete thrusterFactory;
    cout << "Destoyed Stage Factory" << endl;
}

StageFactory::StageFactory(ThrusterFactory* t) 
{
    cout << "Created Stage Factory" << endl;
    thrusterFactory = t;
}


Stage* StageFactory::createSmallStage() 
{

    Stage* s = new Stage();
    s->addThruster(thrusterFactory->createVaccumeThruster());               // attaches one vaccume merlin engine
    return s;
}

Stage* StageFactory::createLargeStage(bool falcon9thruster = true) 
{
    Stage* s = new Stage();
    if(falcon9thruster){
        s->addThruster(thrusterFactory->createCoreThruster());              // attaches one falcon core thruster

    }
    else{
        for  (int i = 0; i < 3; i++)
            s->addThruster(thrusterFactory->createCoreThruster());          // attaches three falcon core thruster
    }

    return s;

}


