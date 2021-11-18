#ifndef THRUSTER_H
#define THRUSTER_H

/**
 * @brief Interface for the composite/decorator class
 * @class Thruster
 */

class Thruster
{
    public:
        /**
         * @brief method which simulates the thruster turning on 
         * @return void
         */
        virtual void fire() = 0;
        /**
         * @brief turns the thrusters off
         * 
         */
        virtual void stop() = 0;
        /**
         * @brief method which adds a thruster to a list returns true if succesful
         * @return bool
         */
        virtual bool addThruster(Thruster* thruster);
        /**
         * @brief method which removes a thruster from a list returns true if succesful
         * @return bool
         */
        virtual bool removeThruster(Thruster* thruster);
};

#endif