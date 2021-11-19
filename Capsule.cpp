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
    Iterator * it = satStorage->createIterator();
    std::cout << "Deploying " << name << "'s Satellites to Global Netwwork: \n";
    for (it->first(); !it->end(); it->next())
    {   
        std::cout << "Deployed Satellite with ID: " << it->current()->getID() << "\n";
        glbNetwork->addSatellite(it->current());
    }

    satStorage->clear();
    delete it;
    
}

bool Capsule::addToNetwork(StarlinkSatellite * satellite)
{
    if (satStorage->getSize() == capacity)
    {
        std::cout << "The satellite storage is maxed out on " << name << std::endl;
        return false;
    }

    std::cout << "The satellite " << satellite->getID() <<" has been added to the storage of " << name << std::endl;
    satStorage->addSatellite(satellite);
    return true;
}