#include "satelliteIterator.h"

/**
	*@param e
	* 	The vector of StarlinkSatellites from an existing aggregate.
*/
SatelliteIterator::SatelliteIterator(std::vector<StarlinkSatellite*> e) : Iterator()
{
	this->list = e;
	this->currentPos = 0;
}

/**
	*first() moves the pointer to the first item in list
*/
void SatelliteIterator::first()
{
	currentPos = 0;
}

/**
 	*Advances the position of pointer to the next element
*/
void SatelliteIterator::next()
{
	currentPos++;
}

/**
 	*Performs a check to determine if at end of list
*/
bool SatelliteIterator::end()
{
	return (currentPos == list.size());
}

/**
	*current returns the current item.
	* returns null if we have reached the end of the list
*/
StarlinkSatellite* SatelliteIterator::current()
{
	if(currentPos >= list.size())
		return NULL;
	else
		return list.at(currentPos);
}