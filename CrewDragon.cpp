#include "CrewDragon.h"

CrewDragon::CrewDragon() : Capsule("Crew Dragon") {
    crew.push_back(new Crew("John", "Doctor")); //add some basic crew
    crew.push_back(new Crew("Jane", "Technician"));
}

CrewDragon::~CrewDragon() 
{
    if (crew.size() != 0)
    {
        std::vector<Crew *>::iterator it;

        for (it = crew.begin(); it != crew.end(); it++)
            delete (*it);
            (*it) = nullptr;

    }
}

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

bool CrewDragon::addCrew(Crew * person)
{
    if (crew.size() == capacity)
    {
        std::cout << "No more crew members can fit in this capsule\n";
        return false;
    }
    std::cout << "Adding " << person->getName() << " \n";
    crew.push_back(person);
    return true;
}