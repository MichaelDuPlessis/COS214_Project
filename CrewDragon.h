#ifndef CREWDRAGON_H
#define CREWDRAGON_H

#include "Capsule.h"
#include "network.h"
#include "StarlinkSatellite.h"

/**
 * @class CrewDragon
 * @brief Class which is the Concrete Class in the Template Method
 */
class CrewDragon : public Capsule
{
private:
    /**     * @brief vector of Crew to be carried on this Capsule.     */
    std::vector<Crew *> crew;
    /**     * @brief the maximum capacity of Crew members available on this Capsule.    */
    int capacity;
public:
    /**     * @brief Constructor for a CrewDragon Capsule; invokes Capsule Constructor.   */
    CrewDragon();
    /**     * @brief Destroys this CrewDragon Capsule.     */
    ~CrewDragon();
    /**     
     * @brief Implements the pure virtual base function; deletes Crew members as it unloads.    
     * @return void
     */
    void unloadCrew();
    /**     
     * @brief Implements the pure virtual base function; unloads the CrewDragon Capsule's cargo.     
     * @return void
     */
    void unloadContents();
    /**     
     * @brief adds a Crew member to the crew vector; returns     
     * @return true
     * @return false
     * return value on whether the Crew member was successfully added to the vector
     */
    bool addCrew(Crew *);

    /**
     * @brief removes all crew
     * 
     */
    void removeCrew();
};



#endif