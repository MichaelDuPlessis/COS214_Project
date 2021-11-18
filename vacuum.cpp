#include "vacuum.h"
#include <iostream>

Vaccuum::Vaccuum()
{
    this->thruster = nullptr;
    this->deleteThruster = false;
}

Vaccuum::Vaccuum(bool deleteThruster) : deleteThruster(deleteThruster) { this->thruster = nullptr; }

Vaccuum::Vaccuum(Thruster* thruster) : thruster(thruster) { this->deleteThruster = false; }

Vaccuum::Vaccuum(Thruster* thruster, bool deleteThruster) : thruster(thruster), deleteThruster(deleteThruster) {}

Vaccuum::~Vaccuum()
{
    if (this->deleteThruster && this->thruster)
        delete this->thruster;
}

void Vaccuum::fire()
{
    std::cout << "Vaccuum ";
    this->thruster->fire();
}

void Vaccuum::stop()
{
    std::cout << "Vaccuum ";
    this->thruster->stop();
}

bool Vaccuum::set(Thruster* thruster)
{
    bool replacing = this->thruster != nullptr;

    this->thruster = thruster;

    return replacing;
}

bool Vaccuum::remove()
{
    if (!this->thruster)
        return false;

    delete this->thruster;
    this->thruster = nullptr;
    
    return true;
}

bool Vaccuum::remove(bool del)
{
    if (del)
        return this->remove();

    if (!this->thruster)
        return false;

    this->thruster = nullptr;
    
    return true;
}