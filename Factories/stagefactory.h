#ifndef STAGEFACTORY_H
#define STAGEFACTORY_H

#include <iostream>
// #include "stage.h"
#include "../thruster.h"
#include "../Stage.h"
#include "thrusterfactory.h"

using namespace std; 
/** 
 * @brief Stage Factory
 * @details Used to create various kinds of stages
 */
class StageFactory
{
private:
    /** * @brief Thruster Factory used for adding thrusters to stages.  */
    ThrusterFactory* thrusterFactory ;
public:
    /**  * @brief Satellite Factory Constructor.  */
    StageFactory();


    /**  
     *  @brief Satellite Factory Constructor. 
     *  @param[in] t Thruster factory for creating thrusters
    */
    StageFactory(ThrusterFactory* t);

    /**  
     *  @brief stage creator. 
     *  @param[out] Stage* returns second stage of a rocket(vacuum merlin engine)
    */
    Stage* createSmallStage();

    /**  
     *  @brief stage creator. 
     *  @param[out] Stage* returns first stage of a rocket(either falcon heavy or falcon 9 first stage)
    */
    Stage* createLargeStage(bool falcon9thruster);

     /**  
     *  @brief StageFactory Destructor. 
     *  @details deletes thurster factory attached to itself
    */
    ~StageFactory();

};

#endif // STAGEFACTORY_H
