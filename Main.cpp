#include "Thruster.h"
#include "Stage.h"
#include "StageObserver.h"

#include <string>
#include <iostream>

using namespace std;

int main()
{
	//create thrusters and stage
	Thruster *thruster1 = new Thruster();
	Thruster *thruster2 = new Thruster();
	Thruster *thruster3 = new Thruster();
	Stage *stage1 = new Stage();

	//create observers
	StageObserver *o1 = new StageObserver(stage1);
	StageObserver *o2 = new StageObserver(stage1);
	StageObserver *o3 = new StageObserver(stage1);
	StageObserver *o4 = new StageObserver(stage1);
	StageObserver *o5 = new StageObserver(stage1);

	//add Thrusters
	stage1->addThruster(thruster1);
	stage1->addThruster(thruster2);
	stage1->addThruster(thruster3);

	//attach observers
	stage1->attach(o1);
	stage1->attach(o2);
	stage1->attach(o3);
	stage1->attach(o4);
	stage1->attach(o5);

	//start stage
	stage1->startStage();

	cout << "Current Stage warning: " << stage1->getWarning() << endl;

	cout << "Minor damage occured updating warning to minor" << endl;
	stage1->setWarning("Minor");

	cout << "Notifying observers..." << endl;
	stage1->notify();
	cout << "\n\n";

	cout << "Detaching 2 observers:" << endl;
	stage1->detach(o1);
	stage1->detach(o2);

	cout << "Major damage occured updating warning to Major" << endl;
	stage1->setWarning("Major");

	cout << "Notifying observers..." << endl;
	stage1->notify();
	cout << "\n\n";

	//land
	stage1->land();

	//stop stage
	stage1->stopStage();

	cout << "Detaching remaining observers:" << endl;
	stage1->detach(o3);
	stage1->detach(o4);
	stage1->detach(o5);
	cout << "\n\n";

	//remove Thrusters
	stage1->removeThruster(thruster1);
	stage1->removeThruster(thruster2);
	stage1->removeThruster(thruster3);

	cout << "Destructing..." << endl;

	//clean up
	delete o5;
	delete o4;
	delete o3;
	delete o2;
	delete o1;

	delete stage1;

	delete thruster3;
	delete thruster2;
	delete thruster1;

	return 0;
}
