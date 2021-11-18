#ifndef LAND_H
#define LAND_H

#include "command.h"

class Land : public Command
{
	 public:
	 	Land(Rocket*);
	 	void launch();
	 	void land();
};

#endif