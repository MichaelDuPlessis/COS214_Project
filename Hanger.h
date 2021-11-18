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
         * @brief private vector of memento's
         * 
         */
        vector<RState*> storage;

    public:
        Hanger();
        ~Hanger(); 
        
        /**
         * @brief function to add a memento
         * 
         * @param rState 
         */
        void addMemento(RState* rState);
        /**
         * @brief function to get the last Memento object
         * 
         * @return RState* 
         * @return nullptr
         * return is based on whether the vector is empty or not
         */
        RState* getMemento();
        /**
         * @brief function to get the Memento object at a specified index
         * 
         * @param index 
         * @return RState* 
         * @return nullptr
         * return is based on whether the vector is empty or not, and whether a valid index was supplied
         */
        RState* getMemento(int index);

    
};

#endif