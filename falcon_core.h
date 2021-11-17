#ifndef FALCON_CORE_H
#define FALCON_CORE_H

#include "thruster.h";
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
        FalconCore(bool deleteThrusters);
        ~FalconCore();

        void fire();
        bool addThruster(Thruster* thruster);
        bool removeThruster(Thruster* thruster);

    private:
        std::vector<Thruster*> thrusters;
        bool deleteThrusters;
};

#endif