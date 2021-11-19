#include "vacuum.h"
#include <iostream>

Vacuum::Vacuum()
{
    this->thruster = nullptr;
    this->deleteThruster = false;
}

Vacuum::Vacuum(bool deleteThruster) : deleteThruster(deleteThruster) { this->thruster = nullptr; }

Vacuum::Vacuum(Thruster* thruster) : thruster(thruster) { this->deleteThruster = false; }

Vacuum::Vacuum(Thruster* thruster, bool deleteThruster) : thruster(thruster), deleteThruster(deleteThruster) {}

Vacuum::~Vacuum()
{
    if (this->deleteThruster && this->thruster)
        delete this->thruster;
}

void Vacuum::fire()
{
    std::cout << "Vacuum ";
    this->thruster->fire();
}

void Vacuum::stop()
{
    std::cout << "Vacuum ";
    this->thruster->stop();
}

bool Vacuum::set(Thruster* thruster)
{
    bool replacing = this->thruster != nullptr;

    this->thruster = thruster;

    return replacing;
}

bool Vacuum::remove()
{
    if (!this->thruster)
        return false;

    delete this->thruster;
    this->thruster = nullptr;
    
    return true;
}

bool Vacuum::remove(bool del)
{
    if (del)
        return this->remove();

    if (!this->thruster)
        return false;

    this->thruster = nullptr;
    
    return true;
}