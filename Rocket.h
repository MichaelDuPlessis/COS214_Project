#ifndef ROCKET_H
#define ROCKET_H

#include <string>
#include <iostream>

#include "LLStrategy.h"

using namespace std;

class Rocket
{
private:
   LLStrategy* strategy;
public:
    Rocket(LLStrategy*);
    void launch(); //algorithms
    void land(); //
};
#endif