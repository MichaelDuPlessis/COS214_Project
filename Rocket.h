#ifndef ROCKET_H 
#define ROCKET_H

#include <iostream>
#include <vector>
#include "Stage.h"
#include "LLStrategy.h"
#include "RState.h"
using namespace std;

class Rocket {
    private:
        vector<Stage*> stages;
        LLStrategy strategy;


    public:
        Rocket();
        void launch();
        void land();
        RState createRState();
        void setRState(RState rState);
        Rocket* clone();


};

#endif