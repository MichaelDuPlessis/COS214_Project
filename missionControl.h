#ifndef MISSIONCONTROL_H
#define MISSIONCONTROL_H

#include "land.h"
#include "launch.h"

class MissionControl 
{
	private:
		Command* _launch;
		Command* _land;
	public:
		MissionControl(Command* launch, Command* land);
		~MissionControl();
		void launch();
		void land();
};
#endif