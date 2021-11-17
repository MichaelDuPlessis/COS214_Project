#include "network.h"

Network::Network() : Aggregate()
{
	//For now empty
}

Network::~Network()
{
	//Source for potential problem when implementations get joined together
	if((this->getSatellites()).size() != 0)//avoid empty list
	{
		std::vector<StarlinkSatellite*>::iterator it = (this->getSatellites()).begin();
		for(it; it != (getSatellites()).end(); ++it)
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
	return new SatelliteIterator(this->getSatellites());
}