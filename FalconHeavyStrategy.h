#ifndef FALCONHEAVYSTRATEGY_H
#define FALCONHEAVYSTRATEGY_H

#include <string>
#include "LLStrategy.h"
using namespace std;

class FalconHeavyStrategy : public LLStrategy
{
private:

public:
    FalconHeavyStrategy();
    void launch();
    void land();
};
#endif
