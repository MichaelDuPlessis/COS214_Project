#ifndef SATELLITEFACTORY_H
#define SATELLITEFACTORY_H

class Satellite;

class SatelliteFactory
{
public:
    SatelliteFactory();

    Satellite* createSatellite();

    ~SatelliteFactory();
};



#endif