#include "Stage.h"
#include "StageObserver.h"

#include <iostream>

using namespace std;

Stage::Stage(Thruster *t)
{
	this->thruster = t;
	this->warning = "none";
	cout << "New Stage Created!" << endl;
}

Stage::~Stage()
{
	cout << "Stage Destroyed!" << endl;
}

void Stage::startStage()
{
	this->thruster->fire();
}

void Stage::stopStage()
{
	this->thruster->stop();
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

	cout << "Observer detached!" << endl;
}

void Stage::attach(StageObserver *obs)
{
	this->stageObservers.push_back(obs);
	cout << "New Observer attached!" << endl;
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
		cout << "Observer notified!" << endl;
	}
}