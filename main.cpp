#include "CrewDragon.h"
#include "Dragon.h"
#include "network.h"

using namespace std;

int main() 
{
    Dragon * dragon = new Dragon();
    CrewDragon * crewdragon = new CrewDragon();
    Network * glbNetwork = new Network();

    for (int i=0;i<61;i++)
    {
        dragon->addToNetwork(new StarlinkSatellite(i));
    }


    dragon->dockToISS(glbNetwork);

    return 0;
}