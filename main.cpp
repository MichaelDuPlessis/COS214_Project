#include <iostream>
#include <string>
#include <map>
#include "Factories/rocketfactory.h"
#include "Factories/satellitefactory.h"
#include "Hanger.h"
#include "Rocket.h"
#include "launch.h"
#include "land.h"
#include "MasterNetwork.h"

#include "thruster_unittest.cpp"
#include "stage_unittest.cpp"
#include "crew_unittest.cpp"
#include <gtest/gtest.h>

using namespace std;

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
/*// building rocket
// creating rocket
Rocket* getRocket(string name, bool crew);
// asks for name of rocket
string getName();
// asks if there is crew
bool hasCrew();
// sets the crew
void setCrew(Rocket* rocket);
// removes crew
void remCrew(Rocket* rocket);
// creates the sattellites
void setSat(Rocket* rocket);
// removes all satellites
void remSat(Rocket* rocket);
// what rocket to modify rocket
int modify(map<string, int> rockets);
// modifies rocket
void modRocket(Rocket* rocket);
// adds warnings to stages
void stageWarn(Rocket* rocket);

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
    // map of name to int
    map<string, int> rockets;

    // greeting text for the user
    cout << "Welcome to the SpaceX Launch Simulation\n";
    cout << "You will be required to make as many test rockets as you want to launc\n";

    cout << "Type 'done' at any point to end the construction of Rockets\n\n";
    // need to check done after eveery function call
    while (!done)
    {
        Rocket* rocket;
        // asking if a rocket should be modified
        int mod = -1;
        if (rockets.size() > 0)
            mod = modify(rockets);

        if (done)
        {
            continue;
        }

        if (mod >= 0) // if modifying a rocket
        {
            rocket = new Rocket(hanger.getMemento(mod));

            modRocket(rocket);
        }
        else // if adding new rocket
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
            rocket = getRocket(name, crew);
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
        }

        // saving rocket
        if (rocket)
        {
            hanger.addMemento(rocket->createRState());

            cout << "Rocket stored in hanger\n";
            rockets.insert(pair<string, int>(rocket->getName(), numRockets++));           
            
            // this is to make sure that there are not memory leaks
            rocket->clear();
            delete rocket;
        }
    }

    // launchind landing the rockets
    cout << "======Launching Rockets======\n\n";

    Launch launch;
    Land land;
    for (int i = 0; i < numRockets; i++)
    {
        Rocket* rocket = new Rocket(hanger.getMemento());
        if (rocket->canLaunch())
        {
            cout << "======" << rocket->getName() << " is launching======\n\n";
            launch.setRocket(rocket);
            launch.launch();
            land.setRocket(rocket);
            land.land();
            cout << "\n======launching finished======\n\n";
        }
        else
        {
            cout << rocket->getName() << " is un able to launch due to a problem with on of the stages\n\n";
        }

        delete rocket;
    }

    // communicating globally
    MasterNetwork::instance()->communicate();

    return 0;
}

void stageWarn(Rocket* rocket)
{
    string input;
    cout << "Would you like to add a warning to a stage (y/n): ";
    cin >> input;

    if (input == "y")
        while (true)
        {
            cout << "What stage would you like to add a warning too: ";
            cin >> input;

            if (checkIfNum(input))
            {
                int num = stoi(input);

                if (rocket->setStageWarning("problem", num))
                {
                    rocket->updateStageObs(num);
                    return;
                } 
                else
                    cout << "No such stage exists\n";
            } 
            else // if none of the if statments triggered than cleary there was an error in input
                invalidInput();
            
        }
}

void modRocket(Rocket* rocket)
{
    string input;
    cout << "What would you like to modify of the Rocket (kind, crew, satellites): ";
    cin >> input;

    if (input == "kind")
    {
        cout << "This will delete the whole rocket and ask you to make a new one\n";
        cout << "Are you sure (y/n): ";
        cin >> input;

        if (input == "y") {
            delete rocket;
            rocket = nullptr;
        }
    }
    else if (input == "crew")
    {
        cout << "Would you like to add or remove crew (add/rem): ";
        cin >> input;

        if (input == "add")
        {
            setCrew(rocket);
        }
        if (input == "rem")
        {
            cout << "Are you sure, this will delete all crew (y/n): ";
            cin >> input;

            if (input == "y")
                remCrew(rocket);
        }
    }
    else if (input == "satellites")
    {
        cout << "Would you like to add or remove satellites (add/rem): ";
        cin >> input;

        if (input == "add")
        {
            setSat(rocket);
        }
        if (input == "rem")
        {
            cout << "Are you sure, this will delete all satellites (y/n): ";
            cin >> input;

            if (input == "y")
                remSat(rocket);
        }
    }
}

int modify(map<string, int> rockets)
{
    string input;
    cout << "Would you like to modify a rocket (y/n): ";
    cin >> input;

    if (input == "end")
    {
        done = true;
        return -1;
    }

    if (input == "y")
        while (true)
        {
            cout << "What rocket would you like to modify: ";
            cin >> input;

            if (rockets.count(input) > 0)
            {
                return rockets[input];
            }

            // if none of the if statments triggered than cleary there was an error in input
            cout << "No rocket with such name exists\n";
        }

    return -1;
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
                    if (!rocket->addPayload(satelliteFactory.createSatellite()))
                    {
                        cout << "Cargo is full\n";
                        break;
                    }
                    
                return;
            }
        }

        // if none of the if statments triggered than cleary there was an error in input
        invalidInput();
    }
}

void remSat(Rocket* rocket)
{
    rocket->removePayoad();
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

                    if (!rocket->addCrew(new Crew(name, spec)))
                    {
                        cout << "Capsule is full\n";
                        break;
                    }
                }

                return;
            }
        }

        // if none of the if statments triggered than cleary there was an error in input
        invalidInput();
    }
}

void remCrew(Rocket* rocket)
{
    rocket->removeCrew();
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
*/