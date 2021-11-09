#include "command.h"

Command::Command(Rocket* input)
{
	this->rocket = input;
}
Command::~Command()
{
	if(this->rocket != NULL)
		delete rocket;
}
void Command::setRocket(Rocket* i)
{
	this->rocket = i;
}

Rocket* Command::getRocket()
{
	return this->rocket;
}