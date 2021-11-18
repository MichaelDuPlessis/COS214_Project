#include "stagefactory.h"


StageFactory::StageFactory()
{
    cout << "Created Stage Factory" << endl;
}

StageFactory::StageFactory(MerlinFactory* m) 
{
    merlinFactory = m;
}


Stage* StageFactory::createSmallStage() 
{
    
}

Stage* StageFactory::createLargeStage() 
{
    
}


