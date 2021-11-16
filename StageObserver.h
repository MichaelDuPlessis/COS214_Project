/*
	Completed By: 
		Name: Jonah Gasura
		Student Number: 20592061

*/		

#ifndef STAGEOBSERVER_H
#define STAGEOBSERVER_H

#include "Stage.h"
#include <string>

using namespace std;

class StageObserver
{

public:
	StageObserver();

	~StageObserver();

	void update();

private: 
	string warning;
	Stage* subject

	
};

#endif