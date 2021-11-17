#ifndef CREW_H
#define CREW_H

#include <string>

class Crew
{
private:
    std::string name;
    std::string specialisation;
    
public:
    Crew();
    ~Crew();
    std::string getName();
    std::string getSpecialisation();
    void setName(std::string);
    void setSpecialisation(std::string);
};


#endif