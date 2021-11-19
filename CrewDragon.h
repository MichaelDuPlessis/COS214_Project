#ifndef CREWDRAGON_H
#define CREWDRAGON_H

#include "Crew.h"
#include "Capsule.h"
#include "network.h"
#include "StarlinkSatellite.h"

class CrewDragon : public Capsule
{
private:
    std::vector<Crew *> crew;
public:
    CrewDragon();
    ~CrewDragon();
    void unloadCrew();
    void unloadContents();

    void addCrew(Crew *);
    Crew * getCrewAtIndex(int);
};



#endif