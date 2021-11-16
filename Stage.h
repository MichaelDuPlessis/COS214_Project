/*
	Completed By: 
		Name: Jonah Gasura
		Student Number: 20592061

*/		

#ifndef STAGE_H
#define STAGE_H

#include "Thruster.h"
#include "StageObserver.h"

#include <string>
#include <vector>

using namespace std;

class Stage
{

public:
	Stage();

	~Stage();

	void startStage();

	void stopStage();

	string getWarning();

	void setWarning(string w);

	void detach(StageObserver* obs);

	void attach(StageObserver* obs);

	void land();

	//additional
	void notify();

private: 
	Thruster* thruster;
	string warning;
	vector<StageObserver*> stageObservers;

	
};

#endif