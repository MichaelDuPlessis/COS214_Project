#ifndef THRUSTER_H
#define THRUSTER_H

class Thruster
{
    public:
        virtual void fire() = 0;
        virtual bool addThruster(Thruster* thruster);
        virtual bool removeThruster(Thruster* thruster);
};

#endif