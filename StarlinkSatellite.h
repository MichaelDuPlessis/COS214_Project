#ifndef STARLINKSATELLITE_H
#define STARLINKSATELLITE_H

#include <string>

class StarlinkSatellite
{
private:
    int id;   
public:
    StarlinkSatellite(int);
    ~StarlinkSatellite();
    int getID();
    void communicateSatellite();
    void communicateGround();

};

#endif