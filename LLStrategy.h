#ifndef LLSTRATEGY_H
#define LLSTRATEGY_H

#include <string>
#include <iostream> // iostream for all derived classes too
using namespace std;

class LLStrategy
{
private:

public:
    LLStrategy() {}; //do we have constructor in abstract class
    virtual void launch() = 0; //pure vitual abstract
    virtual void land() = 0;
};
#endif