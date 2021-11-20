#include <iostream>
#include "Factories/rocketfactory.h"

using namespace std;

int main()
{
    RocketFactory fac;
    Rocket* roc = fac.buildFalcon9(false);

    roc->launch();

    delete roc;

    return 0;
}