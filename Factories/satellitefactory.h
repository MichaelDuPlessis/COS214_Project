#ifndef SATELLITEFACTORY_H
#define SATELLITEFACTORY_H

class Satellite{public: Satellite();};

using namespace std;

class SatelliteFactory
{
public:
    SatelliteFactory();

    Satellite* createSatellite();

    ~SatelliteFactory();
};



#endif