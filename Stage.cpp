#include "Stage.h"
#include "StageObserver.h"

#include <iostream>

using namespace std;

Stage::Stage()
{
	// cout << "New Stage Created!" << endl;
	this->warning = "none";
}

Stage::~Stage()
{
	// cout << "Stage Destroyed!" << endl;
	for (std::vector<Thruster*>::iterator itr = this->thrusters.begin(); itr != this->thrusters.end(); itr++)
        delete (*itr);

	for (std::vector<StageObserver*>::iterator itr = this->stageObservers.begin(); itr != this->stageObservers.end(); itr++)
		if (*itr)
		{
			delete (*itr);
			(*itr) = nullptr;
		}
}

void Stage::startStage()
{
	for (std::vector<Thruster*>::iterator itr = this->thrusters.begin(); itr != this->thrusters.end(); itr++)
        (*itr)->fire();
}

void Stage::stopStage()
{
	for (std::vector<Thruster*>::iterator itr = this->thrusters.begin(); itr != this->thrusters.end(); itr++)
        (*itr)->stop();
}

string Stage::getWarning()
{
	return this->warning;
}

void Stage::setWarning(string w)
{
	this->warning = w;
}

void Stage::detach(StageObserver *obs)
{
	vector<StageObserver *>::iterator it;

	for (it = stageObservers.begin(); it < stageObservers.end(); it++)
	{
		if ((*it) == obs)
			this->stageObservers.erase(it--);
	}

	// cout << "Observer detached!" << endl;
}

void Stage::attach(StageObserver *obs)
{
	this->stageObservers.push_back(obs);
	// cout << "New Observer attached!" << endl;
}

void Stage::land()
{
	cout << "Landed" << endl;
}

//additional - NOT IN THE CLASS DIAGRAM

void Stage::notify()
{
	vector<StageObserver *>::iterator it;

	for (it = stageObservers.begin(); it < stageObservers.end(); it++)
	{

		(*it)->update();
		// cout << "Observer notified!" << endl;
	}
}

void Stage::addThruster(Thruster* thruster)
{
	if (this->thrusters.size() < 3)
		this->thrusters.push_back(thruster);
}

bool Stage::isProblem()
{
	vector<StageObserver *>::iterator it;

	for (it = stageObservers.begin(); it < stageObservers.end(); it++)
		if ((*it)->getWarning() != "none")
			return true;

	return false;
}

StageObserver * Stage::popObs()
{
    if (stageObservers.size() == 0)
        return nullptr;
    else 
    {
        return stageObservers[0];
    }
}

int Stage::getNumThrusters() {
	return thrusters.size();
}