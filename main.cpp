#include "CrewDragon.h"
#include "Dragon.h"
#include "network.h"

using namespace std;

int main() 
{
    Dragon * dragon = new Dragon();
    CrewDragon * crewdragon = new CrewDragon();

    for (int i=0;i<61;i++)
    {
        StarlinkSatellite * temp = new StarlinkSatellite();
        cout << temp->getID() << endl;
        crewdragon->addToNetwork(temp);
    }

    return 0;
}