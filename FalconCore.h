#ifndef FALCON_CORE_H
#define FALCON_CORE_H

#include "Thruster.h";
#include <vector>;

/**
 * @brief Acts as the composite in the composite design pattern
 * @class FalconCore
 */
class FalconCore : Thruster
{
    public:
        /**
         * @brief Construct a new Falcon Core object
         * 
         */
        FalconCore();
        /**
         * @brief Construct a new Falcon Core object
         * 
         * @param deleteThrusters
         * whether the object should delete the thruster
         */
        FalconCore(bool deleteThrusters);
        /**
         * @brief Destroy the Falcon Core object
         * 
         */
        ~FalconCore();

        /**
         * @brief fires all children
         * 
         */
        void fire();
        /**
         * @brief turns off all children
         * 
         */
        void stop();
        /**
         * @brief 
         * 
         * @param thruster 
         * @return true 
         * @return false 
         * return based on whether the object already exists in the vector (true does not exists)
         */
        bool addThruster(Thruster* thruster);
        /**
         * @brief removes the thruster 
         * 
         * @param thruster 
         * @return true 
         * @return false 
         * return is based on if an object was removed (true if found and removed)
         */
        bool removeThruster(Thruster* thruster);

    private:
        /**
         * @brief a vector of thrusters for the falcon core
         * 
         */
        std::vector<Thruster*> thrusters;
        /**
         * @brief whether the object should delete the thrusters or not
         * 
         */
        bool deleteThrusters;
};

#endif