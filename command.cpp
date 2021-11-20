#include "command.h"

Command::Command() {};

/**
	*@brief
	* 		create a command interface for an existing rocket
	* @param input
	* 		A pointer to a rocket which will be controlled
*/
Command::Command(Rocket* input)
{
	this->rocket = input;
}
Command::~Command()
{
	// if(this->rocket != NULL)
	// 	delete rocket;
}

/**
	*@brief
	* 		A setter function to replace current rocket if needed.
*/
void Command::setRocket(Rocket* i)
{
	this->rocket = i;
}
/**
	*@return
	* 		returns the current Rocket of the class
*/
Rocket* Command::getRocket()
{
	return this->rocket;
}