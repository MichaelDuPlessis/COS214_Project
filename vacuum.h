#ifndef VACUUM_H
#define VACUUM_H

#include "thruster.h"

class Vaccuum : Thruster
{
    public:
        /**
         * @brief Construct a new Vaccuum object
         * deleteThruster set to false
         * thruster set to nullpointer
         */
        Vaccuum();
        /**
         * @brief Construct a new Vaccuum object
         * 
         * @param thruster 
         * way to instantiate thruster
         * deleteThruster set to false
         */
        Vaccuum(Thruster* thruster);
        /**
         * @brief Construct a new Vaccuum object
         * 
         * @param deleteThruster 
         * thruster set to nullpointer
         * way to set deleteThruster
         */
        Vaccuum(bool deleteThruster);
        /**
         * @brief Construct a new Vaccuum object
         * 
         * @param thruster 
         * @param deleteThruster 
         * way to set deleteThruster
         * way to instantiate thruster
         */
        Vaccuum(Thruster* thruster, bool deleteThruster);
        /**
         * @brief Destroy the Vaccuum object
         * deletes thruster if deleteThruster set to true
         */
        ~Vaccuum();

        /**
         * @brief prints decorator
         * 
         */
        void print();
        /**
         * @brief sets the current thruster
         * 
         * @param thruster 
         * @return true 
         * @return false 
         * return is based on whether it removed a thruster or if thruster was a nullpointer (true no null pointer)
         */
        bool set(Thruster* thruster);
        /**
         * @brief  removes the current thruster and deletes it
         * 
         * @return true 
         * @return false 
         * return is based on whether thruster was a nullpointer (true if not a null pointer)
         */
        bool remove();
        /**
         * @brief removes the current thruster
         * 
         * @param del 
         * if true than delete the object too
         * @return true 
         * @return false 
         * return is based on whether thruster was a nullpointer (true if not a null pointer)
         */
        bool remove(bool del);

    private:
        Thruster* thruster;
        bool deleteThruster;
};

#endif