#ifndef DRAGON_H
#define DRAGON_H

#include "Capsule.h"

class Dragon : public Capsule
{
public:
    Dragon();
    ~Dragon();
    void unloadContents();

};

#endif