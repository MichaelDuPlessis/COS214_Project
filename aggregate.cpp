#include "aggregate.h"

Aggregate::Aggregate()
{
	//For now empty
}

Aggregate::~Aggregate()
{
	//For now empty
}

std::vector<StarlinkSatellite*> Aggregate::getSatellites()
{
	return this->satellites;
}

void Aggregate::addSatellite(StarlinkSatellite* e)
{
	satellites.push_back(e);
}