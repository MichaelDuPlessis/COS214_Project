#ifndef STAGEFACTORY_H
#define STAGEFACTORY_H

#include <iostream>
// #include "stage.h"
#include "../thruster.h"
#include "thrusterfactory.h"
class MerlinFactory;
class Stage;

using namespace std; 
class StageFactory
{
private:
    MerlinFactory* merlinFactory ;
public:
    StageFactory();
    StageFactory(Thruster* m);
    Stage* createSmallStage();
    Stage* createLargeStage();

};

#endif // STAGEFACTORY_H
