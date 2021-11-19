#include "Capsule.h"

Capsule::Capsule(std::string name) : name(name) {}

Capsule::~Capsule() {}

void Capsule::unloadCrew() 
{
    std::cout << "This capsule has now crew to unload.\n";
}

void Capsule::dockToISS(Network * glbNetwork)
{
    this->deployToNetwork(glbNetwork);
    std::cout << name << " is docking to the International Space Station\n";
    this->unloadCrew();
    this->unloadContents();
    std::cout << name << " has finished unloading its contents on the ISS, detaching...\n";
}

void Capsule::deployToNetwork(Network * glbNetwork)
{
    int count = 0;
    std::vector<StarlinkSatellite *>::iterator it;
    std::cout << "Deploying " << name << "'s Satellites to Global Netwwork: \n";
    for (it = satStorage->getSatellites().begin(); it != satStorage->getSatellites().end(); it++)
    {   
        if (it == satStorage->getSatellites().end())
            std::cout << "Deployed Satellite with ID: " << (*it)->getID() << ".\n";
        else std::cout << "Deployed Satellite with ID: " << (*it)->getID() << ", ";
        delete (*it);

        if (count % 10 == 0)
            std::cout << std::endl;
        count++;
    }
    
    std::cout << satStorage->getSatellites().size() << " - satStorage Size Size\n";
}

bool Capsule::addToNetwork(StarlinkSatellite * satellite)
{
    if (satStorage->getSize() == 0)
    {
        satStorage->addSatellite(satellite);
        return true;
    }
    if (satStorage->getSize() == capacity)
    {
        std::cout << "The satellite storage is maxed out on " << name << std::endl;
        return false;
    }

    satStorage->addSatellite(satellite);
    return true;
}