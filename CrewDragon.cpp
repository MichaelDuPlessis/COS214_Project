#include "CrewDragon.h"

CrewDragon::CrewDragon() {
    crew.push_back(new Crew("John", "Doctor")); //add some basic crew
    crew.push_back(new Crew("Jane", "Technician"));
}

CrewDragon::~CrewDragon() {}

void CrewDragon::unloadCrew() 
{
    std::vector<Crew *>::iterator it;
    std::cout << "Unloading the following Crew: \n";
    for (it = crew.begin(); it != crew.end(); it++)
    {
        std::cout << "Name: "<< (*it)->getName() << "\tSpecialisation: " << (*it)->getSpecialisation() << std::endl;
        delete (*it);
    }
    
    std::cout << crew.size() << " - Crew Size\n";
}

void CrewDragon::unloadContents()
{
    std::cout << "Unloading Cargo from the CrewDragon Capsule\n";
}

