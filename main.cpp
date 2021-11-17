#include "Rocket.h"
#include "FalconHeavyStrategy.h"
#include "Falcon9Strategy.h"
#include "LLStrategy.h"

#include <string>
#include <iostream>

using namespace std;

int main()
{
    LLStrategy* fh = new FalconHeavyStrategy();
  //  LLStrategy* fH = new FalconHeavyStrategy();
    Rocket* r = new Rocket(fh);
    r->launch();

    LLStrategy* f9 = new Falcon9Strategy();
    Rocket* r2 = new Rocket(f9);
    r2->launch();

    return 0;
}