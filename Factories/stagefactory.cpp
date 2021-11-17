#include "stagefactory.h"

StageFactory::StageFactory()
{

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


