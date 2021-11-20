#include "Hanger.h"
#include <iostream>
using namespace std;

void Hanger::addMemento(RState* rState)
{
    this->storage.push_back(rState);
}

RState* Hanger::getMemento()
{
    if(!storage.empty())
    {
        RState* temp = storage.back();
        storage.pop_back();
        return temp;
    }

    return nullptr;
    
}

RState* Hanger::getMemento(int index)
{    
    if(storage.size() <= index || index < 0)
    {
        return nullptr; 
    }
    else
    {
        RState* temp = storage.at(index);
        storage.erase(storage.begin() + index);
        return temp;
    }
}