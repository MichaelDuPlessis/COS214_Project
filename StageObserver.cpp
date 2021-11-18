#include "StageObserver.h"

#include <iostream>

using namespace std;

StageObserver::StageObserver(Stage *s)
{
	this->subject = s;
	this->warning = "none";
	cout << "New StageObserver Created!" << endl;
}

StageObserver::~StageObserver()
{
	cout << "StageObserver Destroyed!" << endl;
}

void StageObserver::update()
{
	string oldWarning = this->warning;

	if (this->subject->getWarning() != this->warning)
		this->warning = this->subject->getWarning();

	cout << "Observer warning message updated: " << oldWarning << " -> " << this->warning << endl;
}