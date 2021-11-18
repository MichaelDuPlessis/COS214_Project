#include "Dragon.h"

Dragon::Dragon() {}

Dragon::~Dragon() {}

void Dragon::printCrew()
{
    std::cout << "Dragon capsule holds no crew\n";
}

// void CrewDragon::printSatellites() {
    // std::vector<StarlinkSatellitess *>::iterator it;

    // for (it = satellites.begin(); it != satellites.end(); it++)
    //     std::cout << "Name: "<< (*it)->getName() << "\tSpecialisation: " << (*it)->getSpecialisation() << std::endl;
// }

void Dragon::dockToISS()
{
    std::cout << "Unloading cargo to ISS\n";
}