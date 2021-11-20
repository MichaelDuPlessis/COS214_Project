#ifndef CAPSULEFACTORY_H
#define CAPSULEFACTORY_H

#include <vector>
#include <iostream>

#include "../Capsule.h"
#include "../Dragon.h"
#include "../CrewDragon.h"

using namespace std;

/** 
 *  @brief     Abstract Capsule Factory
 *  @details   interface to create either Crewdragon or Dragon Capsules
*/

class CapsuleFactory{
public:

    /** 
     * @brief CapsuleFactory's constructor   
     * @return void
     */
    CapsuleFactory();

    /** 
     * @brief CapsuleFactory's pure virtual build function   
     * @return Capsule* 
     */
    virtual Capsule* buildCapsule() = 0;


    /** 
     * @brief CapsuleFactory's destructor   
     * @return void
     */
    virtual ~CapsuleFactory();
};


/** 
 *  @brief     Concrete Capsule Factory
 *  @details   Used to create Crewdragon Capsules
*/
class CD_CapsuleFactory : public CapsuleFactory
{
public:

    CD_CapsuleFactory();

    /** 
     * @brief Crew Dragon build function 
     * @return Crew Dragon Capsule in form of Capsule*
     */
    Capsule* buildCapsule();

    ~CD_CapsuleFactory();
};


/** 
 *  @brief     Concrete Capsule Factory
 *  @details   Used to create Dragon Capsules
*/
class C_CapsuleFactory : public CapsuleFactory{
public:
    C_CapsuleFactory();

    /** 
     * @brief Dragon build function 
     * @return Dragon Capsule in form of Capsule*
     */
    Capsule* buildCapsule();

    ~C_CapsuleFactory();
};


#endif // CAPSULEFACTORY_H
