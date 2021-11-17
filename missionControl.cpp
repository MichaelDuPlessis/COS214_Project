#include "missionControl.h"

/**
 	*@brief
 	* 		Constructor takes two arguments to initialise the classes attributes.
 	* @param launch
 	* 		A launch command,
 	*@param land
 	* 		 A land command
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
/**
	*@brief
	*	Calls the commands launch method to launch the Rocket
*/
void MissionControl::launch()
{
	_launch->launch();
}
/**
	*@brief
	* 	Calls the commands land method to land the Rocket.
*/
void MissionControl::land()
{
	_land->land();
}