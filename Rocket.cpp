#include "Rocket.h"
#include <iostream>
using namespace std;

Rocket::Rocket(LLStrategy* strategy, Capsule* capsule, vector<Stage*> stages) : strategy(strategy), capsule(capsule), stages(stages) {}

void Rocket::launch() 
{
    strategy->launch(); //calling concrete strategy launch and land, client chooses which rocket
}

void Rocket::land() 
{
    strategy->land();
}

*Rocket Rocket::getRocket() { this; }

Rocket::~Rocket()
{
    delete this->capsule;
    delete this->strategy;

    for (std::vector<Stage*>::iterator itr = this->stages.begin(); itr != this->stages.end(); itr++)
        delete (*itr);
}

RState* Rocket::createRState()
{
    return new RState(this->strategy, this->capsule, this->stages, this->target);
}

void Rocket::setRState(RState* rState)
{
    this->strategy = rState->strategy;
    this->capsule = rState->capsule;
    this->stages = rState->stages;
    this->target = rState->target;
}

RState* Rocket::createMemento()
{

}


Rocket* Rocket::clone()
{
    delete this->capsule;
    delete this->strategy;

    for (std::vector<Stage*>::iterator itr = this->stages.begin(); itr != this->stages.end(); itr++)
        delete (*itr);
}

void Rocket::setTarget(Network* target) { this->target = target; }
    // todo once we have factories to make 
    // copies of strategy and stage, maybe use clone witht them
}
