#ifndef ROCKETFACTORY_H
#define ROCKETFACTORY_H

#include "stagefactory.h"
#include "capsulefactory.h"

#include "../Rocket.h"
#include "../Stage.h"
#include "../Capsule.h"
#include "../LLStrategy.h"

#include <vector>
#include <iostream>

using namespace std;

    /** 
     * @brief Rocket Factory. 
     * @details Produces Falcon Heavy and Falcon 9
     */
class RocketFactory
{

private:
    /**  * @brief Holds A stagefactory.  */
    StageFactory* StgFact;
    /**  * @brief Holds A  dragonfactory.  */
    CapsuleFactory* CFact;
    /**  * @brief Holds A crewdragonfactory.  */
    CapsuleFactory* CDFact;

public:
    /** 
     * @brief Rocket Factory Constructor. 
     * @param[out] creates all required factories for a rocketfactory
     */
    RocketFactory();

    /** 
     * @brief Rocket Factory Constructor. 
     * @param[in] Factories takes in required factories
     * @param[out] Factories adds all input factories to a rocketfactory
     */
    RocketFactory(StageFactory *sf, C_CapsuleFactory *cd, CD_CapsuleFactory *d);

    /** 
     * @brief Falcon Heavy creator. 
     * @param[in] s rocket strategy
     * @param[in] crewdragon bool to determine what kind of capsule is to be added
     * @param[out] Rocket* returns a FalconHeavy
     */
    Rocket* buildFalconHeavy(LLStrategy* s, bool crewdragon);

    /** 
     * @brief Falcon Heavy creator. 
     * @param[in] s rocket strategy
     * @param[in] crewdragon bool to determine what kind of capsule is to be added
     * @param[out] Rocket* returns a Falcon9
     */
    Rocket* buildFalcon9(LLStrategy* s, bool crewdragon);


    /** 
     * @brief helper function for creating capsules. 
     * @param[in] crewdragon bool to determine what kind of capsule is to be added
     * @param[out] Capsule* returns either CrewDragon Capsule or Dragon Capsule
     */
    Capsule* builldCapsule(bool crewdragon = true);

    /** 
     * @brief rocket factory destructor. 
     */
    ~RocketFactory();
};

#endif // ROCKETFACTORY_H

