#include "Rocket.h"
#include <iostream>
using namespace std;

Rocket::Rocket(LLStrategy* strategy, Capsule* capsule, vector<Stage*> stages, string name) : strategy(strategy), capsule(capsule), stages(stages), name(name) {}

Rocket::Rocket(RState* rState)
{
    this->strategy = rState->strategy;
    this->capsule = rState->capsule;
    this->stages = rState->stages;
    this->name = rState->name;
}

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
    return new RState(this->strategy, this->capsule, this->stages, this->name);
}

void Rocket::setRState(RState* rState)
{
    this->strategy = rState->strategy;
    this->capsule = rState->capsule;
    this->stages = rState->stages;
    this->name = rState->name;
}

bool Rocket::addPayload(StarlinkSatellite * satellite) 
{
    return this->capsule->addToNetwork(satellite);
}

bool Rocket::addCrew(Crew* crew) 
{
    return this->capsule->addCrew(crew);
}

void Rocket::setName(string name) { this->name = name; }

string Rocket::getName() { return this->name; }

void Rocket::removeCrew() { this->capsule->removeCrew(); }

void Rocket::removePayoad() { this->capsule->removeSatellites(); }

void Rocket::clear()
{
    this->strategy = nullptr;
    this->capsule = nullptr;
    this->stages.clear();
}

bool Rocket::setStageWarning(string w, int pos)
{
    if (pos < 0 || pos >= this->stages.size())
        return false;

    this->stages[pos]->setWarning(w);
    return true;
}

bool Rocket::updateStageObs(int pos)
{
    if (pos < 0 || pos >= this->stages.size())
        return false;

    this->stages[pos]->notify();
    return true;
}

bool Rocket::canLaunch()
{
    for (std::vector<Stage*>::iterator itr = this->stages.begin(); itr != this->stages.end(); itr++)
        if ((*itr)->isProblem())
            return false;

    return true;
}

vector<Stage*> Rocket::getStages(){
    return stages;
}
