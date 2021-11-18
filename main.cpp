#include "land.h"
#include "launch.h"

#include "missionControl.h"
#include<iostream>

int main()
{
	Rocket* r = new Rocket();

	Command* _launch = new Launch(r);
	Command* _land = new Land(r);

	MissionControl* m = new MissionControl(_launch,_land);

	m->launch();
	m->land();
	return 0;
}
