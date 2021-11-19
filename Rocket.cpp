#include "Rocket.h"
#include <iostream>
using namespace std;

Rocket::Rocket(LLStrategy* strategy, Capsule* capsule, vector<Stage*> stages) : strategy(strategy), capsule(capsule), stages(stages) {}

void Rocket::launch() 
{
    strategy->launch(); //calling concrete strategy launch and land, client chooses which rocket

    // iterating through stages
    for (std::vector<Stage*>::iterator itr = this->stages.begin(); itr != this->stages.end(); itr++)
        (*itr)->startStage();
    
    // launching capsule
    this->capsule->dockToISS();
}

void Rocket::land() 
{
    strategy->land();
}

Rocket * Rocket::getRocket() { return this; }

Rocket::~Rocket()
{
    // don't delete this->target as it is a global thing which should be delted in main

    delete this->capsule;
    delete this->strategy;

    for (std::vector<Stage*>::iterator itr = this->stages.begin(); itr != this->stages.end(); itr++)
        delete (*itr);
}

RState* Rocket::createRState()
{
    return new RState(this->strategy, this->capsule, this->stages);
}

void Rocket::setRState(RState* rState)
{
    this->strategy = rState->strategy;
    this->capsule = rState->capsule;
    this->stages = rState->stages;
}

bool Rocket::addPayload(StarlinkSatellite * satellite) 
{
    return this->capsule->addToNetwork(satellite);
}

bool Rocket::addCrew(Crew* crew) 
{
    return this->capsule->addCrew(crew);
}