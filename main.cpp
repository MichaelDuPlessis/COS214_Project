#include "CrewDragon.h"
#include "Dragon.h"

using namespace std;

int main() 
{
    Dragon * dragon = new Dragon();
    CrewDragon * crewdragon = new CrewDragon();

    dragon->printCrew();
    dragon->dockToISS();
    cout << endl;
    crewdragon->printCrew();
    crewdragon->dockToISS();
    crewdragon->printCrew();
    return 0;
}