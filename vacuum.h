#ifndef VACUUM_H
#define VACUUM_H

#include "thruster.h"

class Vaccuum : Thruster
{
    public:
        Vaccuum();
        Vaccuum(Thruster* thruster);
        Vaccuum(bool deleteThruster);
        Vaccuum(Thruster* thruster, bool deleteThruster);
        ~Vaccuum();

        void print();
        bool set(Thruster* thruster);
        bool remove();
        bool remove(bool del);

    private:
        Thruster* thruster;
        bool deleteThruster;
};

#endif