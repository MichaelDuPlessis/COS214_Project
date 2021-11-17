#include "stagefactory.h"

StageFactory::StageFactory()
{

}

Stage *StageFactory::buildStage()
{
    return new Stage();
}
