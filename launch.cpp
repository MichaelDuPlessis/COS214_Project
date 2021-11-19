#include "launch.h"

/**
	*@brief
	* 		A pointer to an instatiated Rocket must be passed to constructor.
	*@param r
	* 			A pointer to an existing rocket.
*/
Launch::Launch(Rocket* r) : Command(r)
{}

/**
	*@brief
	* 		Call the Rockets launch method.
*/
void Launch::launch()
{
	Rocket* r = this->getRocket();
	r->launch();///launch the rocket
}

/**
	*@brief
	* 		Land the rocket
*/
void Launch::land()
{
	//STUB METHOD. Class interested in launch only

	//cout for error handling just in case
	std::cout<<"You are either passed parameters in wrong order";
	std::cout<<"or you are calling land from the wrong class. This is ";
	std::cout<<"launch only\n";
	//Rocket* r = this->getRocket();
	//r->land();
}