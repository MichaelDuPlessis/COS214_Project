#ifndef CREWDRAGON_H
#define CREWDRAGON_H

#include "Crew.h"
#include "Capsule.h"
#include "StarlinkSatellite.h"


class CrewDragon : public Capsule
{
private:
    std::vector<Crew *> crew;
public:
    CrewDragon();
    ~CrewDragon();
    void printCrew();
    // void printSatellites();
    void dockToISS();
    Capsule * clone();

    // std::vector<Crew *> getCrew();
    // void setCrew(std::vector<Crew *>);
    // std::vector<StarlinkSatellite *> getSatellites();
    // void setSatellites(std::vector<StarlinkSatellite *>);
};



#endif