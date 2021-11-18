#ifndef MERLIN_H
#define MERLIN_H

#include "thruster.h"

/**
 * @brief Class which functions as the leaf in the composite design pattern
 * @class Merlin
 */
class Merlin : public Thruster
{
    public:
    /**
     * @brief turns the engine on
     * @return void
     */
    void fire();
    /**
     * @brief turns the engine off
     * 
     */
    void stop();
};

#endif