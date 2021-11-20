#include <iostream>
#include <string>
#include "Factories/rocketfactory.h"
#include "Factories/satellitefactory.h"
#include "Hanger.h"
#include "Rocket.h"

using namespace std;

Rocket* getRocket();
void invalidInput();
    
// boolean whether the user is done making rockets
bool done = false;

int main()
{
    // factories that will be needed
    SatelliteFactory satelliteFactory;
    
    // greeting text for the user
    cout << "Welcome to the SpaceX Launch Simulation\n";
    cout << "You will be required to make as many test rockets as you want to launc\n";

    cout << "Type 'done' at any point to end the construction of Rockets"
    while (!done)
    {
        // asking for rocket type
        
    }

    return 0;
}

Rocket* getRocket()
{
    RocketFactory rocketFactory;
    string input;

    while (true)
    {
        cout << "What kind of rocket would you like (F9/FH): ";
        cin >> input;

        if (input == "end")
            done = true;

        if (input == "F9")
            return rocketFactory.buildFalcon9()
    }
}

void invalidInput(){
    cout << "Invalid input\n";
}