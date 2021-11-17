#include "land.h"

Land::Land(Rocket* r) : Command(r)
{}

/**
	*@brief
	* 		Call the Rockets land method
*/
void Land::land()
{
	Rocket* r = this->getRocket();
	r->land();
}

/**
	*@brief
	* 		Launches the Rocket.
*/
void Land::launch()
{
	//STUB METHOD HERE. Class interested in land() only

	std::cout<<"Either parameters passed in wrong order to missionControl ";
	std::cout<<"or you are calling launch from wrong class. This is ";
	std::cout<<"Land only.\n";
	//Rocket* r = this->getRocket();
	//r->launch();
}