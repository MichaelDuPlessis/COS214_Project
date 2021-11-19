#ifndef STAGEFACTORY_H
#define STAGEFACTORY_H

#include <iostream>
// #include "stage.h"
#include "../thruster.h"
#include "../Stage.h"
#include "thrusterfactory.h"

using namespace std; 
class StageFactory
{
private:
    ThrusterFactory* thrusterFactory ;
public:
    StageFactory();
    StageFactory(ThrusterFactory* t);
    Stage* createSmallStage();
    Stage* createLargeStage(bool falcon9thruster = true);
    ~StageFactory();

};

#endif // STAGEFACTORY_H
