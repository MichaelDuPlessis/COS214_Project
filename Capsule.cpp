#include "Capsule.h"

Capsule::Capsule(std::string name) : name(name)
{
    this->capacity = 60;
}

Capsule::~Capsule() 
{
}

// should never be called in this class
bool Capsule::addCrew(Crew* crew)
{
    return false;
}

void Capsule::unloadCrew() 
{
    std::cout << "This capsule has no crew to unload.\n";
}

void Capsule::dockToISS()
{
    this->deployToNetwork();
    std::cout << name << " is docking to the International Space Station\n";
    this->unloadCrew();
    this->unloadContents();
    std::cout << name << " has finished unloading its contents on the ISS, detaching...\n";
}

void Capsule::deployToNetwork()
{
    int count = 0;
    Iterator * it = satStorage.createIterator();
    std::cout << "Deploying " << name << "'s Satellites to Global Netwwork: \n";
    for (it->first(); !it->end(); it->next())
    {   
        std::cout << "Deployed Satellite with ID: " << it->current()->getID() << "\n";
        MasterNetwork::instance()->network()->addSatellite(it->current());
    }

    satStorage.clear();
    delete it;
    
}

bool Capsule::addToNetwork(StarlinkSatellite * satellite)
{
    if (satStorage.getSize() == capacity)
    {
        std::cout << "The satellite storage is maxed out on " << name << std::endl;
        return false;
    }

    std::cout << "The satellite " << satellite->getID() <<" has been added to the storage of " << name << std::endl;
    satStorage.addSatellite(satellite);
    return true;
}

void Capsule::removeCrew() {}