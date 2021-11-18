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