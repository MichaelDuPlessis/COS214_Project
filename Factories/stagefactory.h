#ifndef STAGEFACTORY_H
#define STAGEFACTORY_H

#include "stage.h"

class StageFactory
{
public:
    StageFactory();
    Stage* buildStage();

};

#endif // STAGEFACTORY_H
