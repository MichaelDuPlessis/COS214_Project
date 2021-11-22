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
    if (this->capsule)
        delete this->capsule;
    this->capsule = nullptr;

    if (this->strategy)
        delete this->strategy;
    this->strategy = nullptr;

    if (stages.size() > 0)
        while(stages[0]->popObs())
        {
            StageObserver * temp = stages[0]->popObs();
            for (std::vector<Stage*>::iterator itr = this->stages.begin(); itr != this->stages.end(); itr++)
                (*itr)->detach(temp);
            delete temp;
        }
        
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

void Rocket::setStrategy(LLStrategy* strat)
{
    if (this->strategy)
        delete this->strategy;
    this->strategy = strat;
}

string Rocket::getStrategy() { return this->strategy->getKind(); }

Capsule* Rocket::getCapsule() { return this->capsule; }

Capsule* Rocket::getCapsuleNull()
{
    Capsule* temp = this->capsule;
    this->capsule = nullptr;
    return temp;
}

void Rocket::replaceCapsule(Capsule* cap)
{
    if (this->capsule)
        delete this->capsule;

    this->capsule = cap;
}
vector<Stage*> Rocket::getStages(){
    return stages;
}
