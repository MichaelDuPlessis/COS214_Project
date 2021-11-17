#ifndef FALCON_CORE_H
#define FALCON_CORE_H

#include "thruster.h";
#include <vector>;

class FalconCore : Thruster
{
    public:
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