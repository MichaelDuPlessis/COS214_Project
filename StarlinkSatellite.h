#ifndef STARLINKSATELLITE_H
#define STARLINKSATELLITE_H

#include <string>

class StarlinkSatellite
{
private:
    static int id;   
public:
    StarlinkSatellite();
    ~StarlinkSatellite();
    int getID();
    void communicateSatellite();
    void communicateGround();

};

#endif