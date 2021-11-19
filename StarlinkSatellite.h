#ifndef STARLINKSATELLITE_H
#define STARLINKSATELLITE_H

class StarlinkSatellite
{
private:
    int id;   
public:
    StarlinkSatellite(/* args */);
    ~StarlinkSatellite();
    void communicateSatellite();
    void communicateGround();


};

#endif