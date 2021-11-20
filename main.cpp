#include <iostream>
#include <string>
#include "Factories/rocketfactory.h"
#include "Factories/satellitefactory.h"
#include "Hanger.h"
#include "Rocket.h"
#include "launch.h"
#include "land.h"

using namespace std;

// building rocket
// creating rocket
Rocket* getRocket(string name, bool crew);
// asks for name of rocket
string getName();
// asks if there is crew
bool hasCrew();
// sets the crew
void setCrew(Rocket* rocket);
// creates the sattellites
void setSat(Rocket* rocket);

// helpers
bool checkIfNum(string &str);

// errors
void invalidInput();
    
// boolean whether the user is done making rockets
bool done = false;

int main()
{
    // caretaker
    Hanger hanger;
    // number of rockets created
    int numRockets = 0;

    // greeting text for the user
    cout << "Welcome to the SpaceX Launch Simulation\n";
    cout << "You will be required to make as many test rockets as you want to launc\n";

    cout << "Type 'done' at any point to end the construction of Rockets\n\n";
    // need to check done after eveery function call
    while (!done)
    {
        // getting rocket name
        string name = getName();
        if (done)
        {
            continue;
        }

        // getting crew
        bool crew = hasCrew();
        if (done)
        {
            continue;
        }

        // asking for rocket type
        Rocket* rocket = getRocket(name, crew);
        if (done)
        {
            delete rocket;
            continue;
        }

        // getting crew if any
        if (crew)
        {
            setCrew(rocket);
            if (done)
            {
                delete rocket;
                continue;
            }
        }

        // setting sats if any
        setSat(rocket);
        if (done)
        {
            delete rocket;
            continue;
        }

        // saving rocket
        hanger.addMemento(rocket->createRState());

        cout << "Rocket stored in hanger\n";
        numRockets++;
    }

    Launch launch;
    Land land;
    for (int i = 0; i < numRockets; i++)
    {
        Rocket* rocket = new Rocket(hanger.getMemento());
        launch.setRocket(rocket);
        launch.launch();
        land.setRocket(rocket);
        land.land();

        delete rocket;
    }

    return 0;
}

void setSat(Rocket* rocket)
{
    string input;
    SatelliteFactory satelliteFactory;

    while (true)
    {
        cout << "How many satellites do you want (0<=n<=60): ";
        cin >> input;

        if (checkIfNum(input))
        {
            int sat = stoi(input);
            if (sat <= 60 && sat >= 0) {
                for (; sat > 0; sat--)
                    rocket->addPayload(satelliteFactory.createSatellite());
                    
                return;
            }

        }

        // if none of the if statments triggered than cleary there was an error in input
        invalidInput();
    }
}

void setCrew(Rocket* rocket)
{
    string input;

    while (true)
    {
        cout << "How many crew members would you like (0<=n<=7): ";
        cin >> input;

        if (checkIfNum(input))
        {
            int crew = stoi(input);
            if (crew <= 7 && crew >= 0) {
                for (; crew > 0; crew--)
                {
                    string name, spec;
                    cout << "What is the crew members name: ";
                    cin >> name;
                    cout << "What is the crew members specialisation: ";
                    cin >> spec;

                    rocket->addCrew(new Crew(name, spec));
                }

                return;
            }
        }

        // if none of the if statments triggered than cleary there was an error in input
        invalidInput();
    }
}

bool hasCrew()
{
    string input;

    while (true)
    {
        cout << "Will your rocket be carrying crew (y/n): ";
        cin >> input;

        if (input == "end") {
            done = true;
            return false;
        }

        if (input == "y")
            return true;
        
        if (input == "n")
            return false;

        // if none of the if statments triggered than cleary there was an error in input
        invalidInput();
    }
}

string getName()
{
    string input;

    while (true)
    {
        cout << "What is the name of your rocket?: ";
        cin >> input;

        if (input == "end") {
            done = true;
            return "";
        }

        if (input != "")
            return input;

        // if none of the if statments triggered than cleary there was an error in input
        invalidInput();
    }
}

Rocket* getRocket(string name, bool crew)
{
    RocketFactory rocketFactory;
    string input;

    while (true)
    {
        cout << "What kind of rocket would you like (F9/FH): ";
        cin >> input;

        if (input == "end") {
            done = true;
            return nullptr;
        }

        if (input == "F9")
            return rocketFactory.buildFalcon9(name, crew);

        if (input == "FH")
            return rocketFactory.buildFalconHeavy(name, crew);

        // if none of the if statments triggered than cleary there was an error in input
        invalidInput();
    }
}

void invalidInput(){
    cout << "Invalid input\n";
}

bool checkIfNum(string &str){
    return str.find_first_not_of("0123456789") == std::string::npos;
}