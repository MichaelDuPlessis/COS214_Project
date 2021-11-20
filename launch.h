#ifndef LAUNCH_H
#define LAUNCH_H

#include "command.h"

class Launch : public Command
{
	 public:
		Launch();
	 	Launch(Rocket*);
	 	void launch();
	 	void land();
};

#endif