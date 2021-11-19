#include "CrewDragon.h"

CrewDragon::CrewDragon() {
    crew.push_back(new Crew("John", "Doctor")); //add some basic crew
    crew.push_back(new Crew("Jane", "Technician"));
}

CrewDragon::~CrewDragon() {}

void CrewDragon::printCrew() 
{
    std::vector<Crew *>::iterator it;

    for (it = crew.begin(); it != crew.end(); it++)
        std::cout << "Name: "<< (*it)->getName() << "\tSpecialisation: " << (*it)->getSpecialisation() << std::endl;
}

// void CrewDragon::printSatellites() {
    // std::vector<StarlinkSatellitess *>::iterator it;

    // for (it = satellites.begin(); it != satellites.end(); it++)
    //     std::cout << "Name: "<< (*it)->getName() << "\tSpecialisation: " << (*it)->getSpecialisation() << std::endl;
// }

void CrewDragon::dockToISS() 
{
    std::cout << "Unloading crew and cargo to ISS\n";
    for (int i=0; i<=crew.size(); i++)
        crew.pop_back();
}

std::vector<Crew *> CrewDragon::getCrew()
{    return crew;   }

void CrewDragon::setCrew(std::vector<Crew *> inCrew) 
{   crew = inCrew;  }
