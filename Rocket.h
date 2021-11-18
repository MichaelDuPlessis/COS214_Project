#ifndef ROCKET_H
#define ROCKET_H

#include <string>
#include <iostream>
#include <vector>

#include "LLStrategy.h"
#include "RState.h"
#include "Stage.h"


using namespace std;
/** 
 *  @brief     Rocket Class
 *  @details   This class represents the context participant in the strategy hierachy
 *  @author    Angela
 *  @date      November 2021
 */
class Rocket
{
private:
   LLStrategy* strategy; //!< private member, pointer to a strategy
   vector<Stage*> stages;
public:
    //! parameterised constructor
    /*!
        @param s pointer to Strategy
    */
    Rocket(LLStrategy*);
    //! algorithms instatiated in rocket class, same algorithims in strategy classes
    void launch(); 
    //! algorithms instatiated in rocket class, same algorithims in strategy classes
    void land(); 
    /**
     * @brief sets rState to provided variable
     * 
     * @param rState 
     * the state that is used to instantiate the Rocket
     */
    void setRState(RState rState);
    /**
     * @brief Creates a clone of a Rocket
     * 
     * @return Rocket* 
     * returns a copy of the Rocket
     */
    Rocket* clone();
};
#endif