#ifndef RSTATE_H 
#define RSTATE_H

#include "Rocket.h"
using namespace std;

class Capsule;  class Stage; class Network;

/**
 * @brief RState Class
 * @details This class represents the Memento participant of the Memento pattern
 * 
 */
class RState {
    ///Adding Rocket class as friend in order to access private member variables
    friend class Rocket;

    private:
        /**
         * @brief Private pointer variable to the Strategy that will be used
         * 
         */
        LLStrategy* strategy;

        /**
         * @brief Private pointer variable to the capsule
         * 
         */
        Capsule * capsule;

        /**
         * @brief Private vector holding the different stages of the Rocket
         * 
         */
        vector<Stage*> stages;

        /**
         * @brief the name of the Rocket
         * 
         */
        string name;

        /**
         * @brief Construct a new RState object
         * Private to ensure base contructor can't be called
         * 
         */
        RState();

        /**
         * @brief Parametised constructer to a new RState object
         * 
         * @param strategy 
         * @param capsule 
         * @param stages 
         * @param target 
         */
        RState(LLStrategy* strategy, Capsule* capsule, vector<Stage*> stages, string name);

    public:
        
        ~RState(); 

       

       
    
};

#endif