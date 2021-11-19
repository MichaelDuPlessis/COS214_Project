#ifndef CREW_H
#define CREW_H

#include <string>

/**
 * @class Crew
 * @brief A class to represent the Crew stored on the CrewDragon Capsule 
 */

class Crew
{
private:
    /**     * @brief a string variable to store the Crew members name.      */
    std::string name;
    /**     * @brief a string variable to store the Crew members specialisation.    */
    std::string specialisation;
     
public:
    /** 
     * @brief constructor for a Crew member object
     * @param name
     * set the name of the Crew member to the parameter
     * @param specialisation
     * set the specialistion of the Crew member to the parameter
     */
    Crew(std::string name, std::string specialisation);
    /**     * @brief Destroy the Crew member object.    */ 
    ~Crew();
    /**     
     * @brief getter for the name variable of the Crew member.  
     * @return string
     */
    std::string getName();
    /**     
     * @brief getter for the specialisation variable of the Crew member.  
     * @return string
     */
    std::string getSpecialisation();

};

#endif