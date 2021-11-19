#ifndef STARLINKSATELLITE_H
#define STARLINKSATELLITE_H

#include <string>

/**
 * @class StarlinkSatellite
 * @brief 
 */
class StarlinkSatellite
{
private:
    /**     * @brief integer variable representing the ID of the StarlinkSatellite.  */
    int id;   
public:
    /**
     * @brief constructor for a StarlinkSatellite object.
     * @param id
     * set the StarlinkSatellite id to the parameter
     */
    StarlinkSatellite();
    /**     * @brief destroy a StarlinkSatellite object.    */
    ~StarlinkSatellite();
    /**
     * @brief getter for the StarlinkSatellite id variable.
     * @return int
     */
    int getID();
    /**
     * @brief function to demonstrate a StarlinkSatellite communicating with the network.
     * @return void
     */
    void communicateSatellite();
    /**
     * @brief function to demonstrate a StarlinkSatellite communicating with the ground.
     * @return void
     */
    void communicateGround();

};

#endif