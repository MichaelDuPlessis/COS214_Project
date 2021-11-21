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

class RState; class Stage;  

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
     * @brief the name of the rocket
     * 
     */
    string name;
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
    Rocket(LLStrategy* strategy, Capsule* capsule, vector<Stage*> stages, string name);

    /**
     * @brief Construct a new Rocket object from a memento
     * 
     * @param state 
     */
    Rocket(RState* rState);

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
     * @brief deletes all satellites in rocket
     * 
     */
    void removePayoad();

    /**
     * @brief adds crew to rockets capsule if possible
     * 
     * @param satellite 
     * @return true 
     * @return false 
     */
    bool addCrew(Crew* crew);
    
    /**
     * @brief removes all crew
     * 
     */
    void removeCrew();

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

    /**
     * @brief Set the Name object
     * 
     * @param name 
     */
    void setName(string name);

    /**
     * @brief Get the Name object
     * 
     * @return string 
     */
    string getName();

    /**
     * @brief sets all vars to null so that when it is deleted nothing else is too
     * 
     */
    void clear();

    /**
     * @brief sets a warning for a the stage
     * 
     * @param w 
     * @param pos 
     * w is the warning
     * pos is the stage
     * 
     * @return true
     * @return false
     * true means stage exists while false the opposite
     */
    bool setStageWarning(string w, int pos);

    /**
     * @brief tells a specific stage to update
     * 
     * @param pos 
     * 
     * @return true
     * @return false
     * true means stage exists while false the opposite
     */
    bool updateStageObs(int pos);

    /**
     * @brief check is any of the observers have a warning
     * 
     * @return true 
     * @return false 
     */
    bool canLaunch();
};
#endif