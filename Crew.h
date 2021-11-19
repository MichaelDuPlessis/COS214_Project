#ifndef CREW_H
#define CREW_H

#include <string>

class Crew
{
private:
    std::string name;
    std::string specialisation;
    
public:
    Crew(std::string, std::string);
    ~Crew();
    std::string getName();
    std::string getSpecialisation();

};

#endif