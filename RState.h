#ifndef RSTATE_H 
#define RSTATE_H

#include <iostream>
#include "State.h"
using namespace std;

class RState {
    private:
       State state;

    public:
        RState();
        ~RState(); 

        State getState();
        void setState(State state);

       
    
};

#endif