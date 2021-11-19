#include "aggregate.h"

Aggregate::Aggregate()
{
	//For now empty
}

Aggregate::~Aggregate()
{
	//For now empty
}

/**
	*@return
	* returns the vector of StarlinkSatellites for the class
*/
std::vector<StarlinkSatellite*> Aggregate::getSatellites()
{
	return this->satellites;
}

/**
	*@param e
	* 		A pointer to an existing StarlinkSatellite which will be added to the vector
*/
void Aggregate::addSatellite(StarlinkSatellite* e)
{
	satellites.push_back(e);
}