#include "RState.h"
#include <iostream>
using namespace std;

RState::RState(LLStrategy * strategy, Capsule* capsule, vector<Stage*> stages, string name)
{
    this->strategy = strategy;
    this->capsule = capsule;
    this->stages = stages;
    this->name = name;
}

RState::~RState() {}