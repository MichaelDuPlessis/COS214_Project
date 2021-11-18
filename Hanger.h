#ifndef HANGER_H 
#define HANGER_H

#include <iostream>
#include <vector>
#include "RState.h"
using namespace std;

/**
 * @brief Hanger Class
 * @details This class represents the Store participant of the Memento pattern
 * 
 */
class Hanger {
    private:
        /**
         * @brief private vector of RState's
         * 
         */
        vector<RState*> storage;

    public:
        Hanger();
        ~Hanger(); 
        
        void addMemento(RState* rState);
        RState* getMemento();
        RState* getMemento(int index);

    
};

#endif