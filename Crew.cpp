#include "Crew.h"

Crew::Crew(std::string name, std::string specialisation) : name(name), specialisation(specialisation) 
{}

Crew::~Crew() {}

std::string Crew::getName() 
{
    return name;
}

std::string Crew::getSpecialisation() 
{
    return specialisation;
}

