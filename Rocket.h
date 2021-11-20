#ifndef ROCKET_H
#define ROCKET_H

#include <string>
#include <iostream>
#include <vector>

#include "LLStrategy.h"
#include "RState.h"
#include "Stage.h"
#include "Capsule.h"
#include "network.h"


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
     * @brief adds a satellite to the rockets current capsule
     * 
     * @param satellite 
     * @return true 
     * @return false 
     */
    bool addPayload(StarlinkSatellite * satellite);

    /**
     * @brief adds crew to rockets capsule if possible
     * 
     * @param satellite 
     * @return true 
     * @return false 
     */
    bool addCrew(Crew* crew);

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
     * @brief reinstatiate Rocket with stored RState variables
     * 
     * @param rState 
     * the state that is used to instantiate the Rocket
     */
    void setRState(RState* rState);

    /**
     * @brief Create new Memento (RState)
     * 
     * @return RState* 
     * The newly created memento
     */
    RState* createRState();
};
#endif