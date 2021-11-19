#include "Capsule.h"

Capsule::Capsule() {}

Capsule::~Capsule() {}

void Capsule::unloadCrew() 
{
    std::cout << "This capsule has now crew to unload.\n";
}

void Capsule::dockToISS(Network * glbNetwork)
{
    this->deployToNetwork(glbNetwork);
    this->unloadContents();
}

bool Capsule::addToNetwork(StarlinkSatellite * satellite)
{
    satStorage->addSatellite(satellite);
}