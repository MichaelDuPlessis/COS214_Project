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
        crewdragon->addToNetwork(new StarlinkSatellite(i));
    }

    crewdragon->addCrew(new Crew("Cara", "disappointment quota"));
    crewdragon->addCrew(new Crew("Mike", "Tisha"));

    crewdragon->dockToISS(glbNetwork);

    return 0;
}