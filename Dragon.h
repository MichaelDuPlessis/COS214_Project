#ifndef DRAGON_H
#define DRAGON_H

#include "Capsule.h"

/**
 * @class Dragon
 * @brief Class which is the Concrete Class in the Template Method
 */
class Dragon : public Capsule
{
public:
    /**     * @brief Constructor for a Dragon Capsule; invokes Capsule Constructor.   */
    Dragon();
    /**     * @brief Destroys the Dragon Capsule object.    */
    ~Dragon();
    /**
     * @brief implements pure virtual base function; unloads cargo from Dragon Capsule. 
     * @return void 
     */
    void unloadContents();

};

#endif