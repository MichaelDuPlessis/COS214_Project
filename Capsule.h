#ifndef CAPSULE_H
#define CAPSULE_H

#include <string>
#include <vector>
#include <iostream>

#include "network.h"
#include "MasterNetwork.h"

/**
 * @class Capsule
 * @brief Class which is the Abstract class in the Template Method
 */
class Capsule 
{
private:
    /** @brief a string variable to store the Capsule name     */
    std::string name;
    /** @brief a Network object representing the StarlinkSatellite storage object on the Capsule     */
    Network * satStorage = new Network();
    /** @brief the maximum capacity of the storage object     */
    const int capacity = 60;
public:
    /**
     * @brief construct a Capsule object
     * @param name
     * set the name of the Capsule to the parameter
     */
    Capsule(std::string name);
    /** @brief Destroy the Capsule object     */
    ~Capsule();

    /**
     *  @brief pure virtual function; unloads the Crew from the Capsule    
     *  @return void
     */
    virtual void unloadCrew();
    /** 
     * @brief pure virtual function; unloads the cargo from the Capsule     
     * @return void
     */
    virtual void unloadContents() = 0;
    /**     
     * @brief add the StarlinkSatellites to the global network and remove it from Capsule storage object    
     */
    void deployToNetwork();
    /**     
     * @brief add StarlinkSatellites to the Capsules storage object     
     * @param satellite
     * the satellite you are adding to the Capsule's storage Network object
     * @return true
     * @return false
     * return value based on whether it successfully added to the storage Network object
     */
    bool addToNetwork(StarlinkSatellite * satellite);

     /**     
     * @brief add the StarlinkSatellites to the global network and remove it from Capsule storage object    
     * @param[out] adds capsules satlellites to global satellites
     * @return void
     */
    void dockToISS();

};

#endif