#ifndef ROCKET_H
#define ROCKET_H

#include <string>
#include <iostream>
#include <vector>

#include "LLStrategy.h"
#include "RState.h"
#include "Stage.h"
#include "Capsule.h"


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
    /**
     * @brief holds the Strategy to be used
     * 
     */
    LLStrategy* strategy; //!< private member, pointer to a strategy
    /**
     * @brief holds the different stages
     * 
     */
    vector<Stage*> stages;
    /**
     * @brief holds the capsule
     * 
     */
    Capsule* capsule;
    /**
     * @brief target network to deliver too (i.e. global network)
     * 
     */
    Network* target;
    /**
     * @brief Construct a new Rocket object
     * to insure that the base constructor cannot be called
     */
    Rocket();
public:
    /**
     * @brief Construct a new Rocket object
     * 
     * @param strategy 
     * @param capsule 
     * @param stages 
     */
    Rocket(LLStrategy* strategy, Capsule* capsule, vector<Stage*> stages);
    /**
     * @brief Destroy the Rocket object
     * Note All private members are deallocated
     */
    ~Rocket();
    /**
     * @brief Get the Rocket object
     * 
     * @return Rocket* 
     */
    Rocket* getRocket();
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
    /**
     * @brief Set the Target object
     * 
     * @param target 
     */
    void setTarget(Network* target);
};
#endif