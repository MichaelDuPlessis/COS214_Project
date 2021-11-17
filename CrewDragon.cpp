#include "CrewDragon.h"

CrewDragon::CrewDragon() {

}

CrewDragon::~CrewDragon() {

}

void CrewDragon::printCrew() {
    std::vector<Crew *>::iterator it;

    for (it = crew.begin(); it != crew.end(); it++)
        std::cout << "Name: "<< (*it)->getName() << "\tSpecialisation: " << (*it)->getSpecialisation() << std::endl;
}

// void CrewDragon::printSatellites() {
    // std::vector<StarlinkSatellitess *>::iterator it;

    // for (it = satellites.begin(); it != satellites.end(); it++)
    //     std::cout << "Name: "<< (*it)->getName() << "\tSpecialisation: " << (*it)->getSpecialisation() << std::endl;
// }
