#ifndef COMMAND_H
#define COMMAND_H

#include "Rocket.h"
#include<iostream>

/**
	*Command Interface with a getter and setter for a Rocket,
	* launch() method which will be called from the Launch concrete class,
	* land() method which will be called from the Land concrete class
*/

class Command
{
	private:
		Rocket* rocket;
	public:
		Command();
		Command(Rocket* );
		virtual ~Command();
		virtual void launch() = 0;
		virtual void land() = 0;
		void setRocket(Rocket*);
		Rocket* getRocket();
};
#endif