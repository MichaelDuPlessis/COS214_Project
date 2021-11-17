#include "falcon_core.h"
#include <iterator>

FalconCore::FalconCore() { this->deleteThrusters = true; }

FalconCore::FalconCore(bool deleteThrusters) : deleteThrusters(deleteThrusters) {}

FalconCore::~FalconCore()
{
    if (this->deleteThrusters)
        for (std::vector<Thruster*>::iterator itr = this->thrusters.begin(); itr != this->thrusters.end(); itr++)
            delete *itr;
}

bool FalconCore::addThruster(Thruster* thruster)
{
    for (std::vector<Thruster*>::iterator itr = this->thrusters.begin(); itr != this->thrusters.end(); itr++)
        if (*itr == thruster)
            return false;

    this->thrusters.push_back(thruster);
    return true;
}

bool FalconCore::removeThruster(Thruster* thruster)
{
    for (std::vector<Thruster*>::iterator itr = this->thrusters.begin(); itr != this->thrusters.end(); itr++)
        if (*itr == thruster) {
            this->thrusters.erase(itr);
            return true;
        }

    return false;
}

void FalconCore::fire()
{
    for (std::vector<Thruster*>::iterator itr = this->thrusters.begin(); itr != this->thrusters.end(); itr++)
        (*itr)->fire();
}