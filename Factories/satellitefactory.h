#ifndef SATELLITEFACTORY_H
#define SATELLITEFACTORY_H

#include "../StarlinkSatellite.h"

using namespace std;

/** 
 * @brief Satellite Factory. 
 * @details Produces Starlin Satellites
 */
class SatelliteFactory
{
public:
    /** 
     * @brief Satellite Factory Constructor. 
     */
    SatelliteFactory();

    /** 
     * @brief Creates starlink satellites. 
     * @param[out] StarlinkSatellite* returns pointer to satellite
     */
    StarlinkSatellite* createSatellite();

    /** 
     * @brief Satellite Factory Constructor. 
     */
    ~SatelliteFactory();
};



#endif