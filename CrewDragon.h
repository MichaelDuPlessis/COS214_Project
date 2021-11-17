#ifndef CREWDRAGON_H
#define CREWDRAGON_H

#include "Crew.h"
#include "Capsule.h"


class CrewDragon : public Capsule
{
private:
//  vector<StarlinkSatellite*> satellites;
    std::vector<Crew *> crew;
public:
    CrewDragon();
    ~CrewDragon();
    void printCrew();
    // void printSatellites();
};



#endif