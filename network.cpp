#include "network.h"
#include <iostream>
Network::Network() : Aggregate()
{
	//For now empty
}

Network::~Network()
{
	if(satellites.size() != 0)//avoid empty list
	{
		std::vector<StarlinkSatellite*>::iterator it = (satellites.begin());
		for(; it != (getSatellites()).end(); ++it)
		{
			delete (*it);//potential error
			(*it) = NULL;
		} 
	}
}
/**
	*@return
	* returns a satellite iterator for the given aggregate
*/
Iterator* Network::createIterator()
{
	//std::cout<<"In createIterator()\n";
	return new SatelliteIterator(satellites);
}

/**
	*@return
	* returns the vector of StarlinkSatellites for the class
*/
std::vector<StarlinkSatellite*> Network::getSatellites()
{
	return satellites;
}

/**
	*@param e
	* 		A pointer to an existing StarlinkSatellite which will be added to the vector
*/
void Network::addSatellite(StarlinkSatellite* e)
{
	satellites.push_back(e);
}

int Network::getSize() 
{
	if (satellites.empty())
		return 0;
	else return satellites.size();
}

void Network::clear() 
{
	satellites.clear();
}