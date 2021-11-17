#ifndef FALCON9STRATEGY_H
#define FALCON9STRATEGY_H

#include <string>
#include "LLStrategy.h"
using namespace std;

class Falcon9Strategy : public LLStrategy
{
private:

public:
    Falcon9Strategy();
    void launch();
    void land();
};
#endif