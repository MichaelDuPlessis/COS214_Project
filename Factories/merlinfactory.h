#ifndef MERLINFACTORY_H
#define MERLINFACTORY_H

using namespace std;
class Merlin{public: Merlin();}; // replace wihu include .h
class MerlinFactory
{
public:
    MerlinFactory();
    Merlin* createMerlin();
    ~MerlinFactory();
};

#endif // MERLINFACTORY_H
