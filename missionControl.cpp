#include "missionControl.h"

/**
 	*Constructor takes two arguments. First being a launch command,
 	*second being a land command. Important they are passed in order
 	* otherwise error messages will be printed to console.
*/
MissionControl::MissionControl(Command* launch, Command* land)
{
	this->_launch = launch;
	this->_land = land;
}

MissionControl::~MissionControl()
{
	if(_launch != NULL)
		delete _launch;

	if(_land != NULL)
		delete _land;
}
void MissionControl::launch()
{
	_launch->launch();
}

void MissionControl::land()
{
	_land->land();
}