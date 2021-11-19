#include "RState.h"
#include <iostream>
using namespace std;

RState::RState(LLStrategy * strategy, Capsule* capsule, vector<Stage*> stages)
{
    this->strategy = strategy;
    this->capsule = capsule;
    this->stages = stages;
}

RState::~RState() {}