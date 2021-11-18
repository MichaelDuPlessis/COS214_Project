#ifndef RSTATE_H 
#define RSTATE_H

#include <iostream>
#include "State.h"
using namespace std;

/**
 * @brief RState Class
 * @details This class represents the Memento participant of the Memento pattern
 * 
 */
class RState {
    private:
       /**
        * @brief private State object variable
        * 
        */
       State state;

    public:
        RState();
        ~RState(); 

        /**
         * @brief Get the State object
         * 
         * @return State 
         */
        State getState();

        /**
         * @brief Set the State object
         * 
         * @param state 
         */
        void setState(State state);

       
    
};

#endif