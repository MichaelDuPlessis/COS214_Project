#ifndef STAGEFACTORY_H
#define STAGEFACTORY_H

// #include "stage.h"
class MerlinFactory;
class Stage;

class StageFactory
{
private:
    MerlinFactory* merlinFactory ;
public:
    StageFactory();
    StageFactory(MerlinFactory* m);
    Stage* createSmallStage();
    Stage* createLargeStage();

};

#endif // STAGEFACTORY_H
