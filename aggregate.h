#ifndef AGGREGATE_H
#define AGGREGATE_H

#include "satelliteIterator.h"

/**
	*Aggregate class serves as an interface in the iterator design pattern	
*/
class Aggregate
{
	 public:
	 	Aggregate();
	 	virtual ~Aggregate();
	 	virtual Iterator * createIterator() = 0;
	
};

#endif