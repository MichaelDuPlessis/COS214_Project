#include "RState.h"
#include <iostream>
using namespace std;

State RState::getState()
{
    return this->state;
}

void RState::setState(State state)
{
    this->state = state;
}