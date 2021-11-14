#ifndef ROCKET_H
#define ROCKET_H

#include <string>
#include <iostream>
using namespace std;

class Rocket
{
private:
    LLStrategy* strategy;
public:
	Rocket();
    void launch(); //algorithms
    void land(); //
};
#endif