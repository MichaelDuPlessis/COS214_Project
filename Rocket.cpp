#include "Rocket.h"
#include <iostream>
using namespace std;


RState Rocket::createRState()
{

}

void Rocket::setRState(RState rState)
{

}

Rocket* Rocket::clone()
{
    // todo once we have factories to make 
    // copies of strategy and stage, maybe use clone witht them
}

Rocket::Rocket(LLStrategy* s) {
    strategy = s;
}

void Rocket::launch() {
    strategy->launch(); //calling concrete strategy launch and land, client chooses which rocket
}

void Rocket::land() {
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