#ifndef THRUSTERFACTORY_H
#define THRUSTERFACTORY_H

#include <iostream>

using namespace std;

#include "../thruster.h"
#include "../FalconCore.h"
#include "../merlin.h"
#include "../vacuum.h"


/** 
 * @brief Thruster Factory
 * @details Used to create various kinds of composite thrusters
 */
class ThrusterFactory
{
public:

    /** 
     * @brief Thruster Constructor
     */
    ThrusterFactory();

    /** 
     * @brief Thruster Creator
     * @details Creates a falcon core thruster
     * @param[out] Thruster* faclon core composite with 9 merlin engines
     */
    Thruster* createCoreThruster();

    /** 
     * @brief Thruster Creator
     * @details Creates a vaccume thruster
     * @param[out] Thruster* single merlin vaccume engine with no core
     */
    Thruster* createVaccumeThruster();

    /** 
     * @brief Custom Thruster Creator
     * @details Creates a custom thruster.
     * @param[out] Thruster* custom composite
     */
    Thruster* customThrustor(bool hascore, int decorated, int engines);

    /** 
     * @brief Thruster destructor
     */
    ~ThrusterFactory();
};

#endif // MERLINFACTORY_H
