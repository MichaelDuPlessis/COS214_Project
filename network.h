#ifndef NETWORK_H
#define NETWORK_H

#include "aggregate.h"

/**
	*Network class serves as a Concrete aggregate in the iterator pattern
	 as seen from the class diagram.
*/
class Network : public Aggregate
{
	 public:
	 	Network();
	 	~Network();
	 	Iterator* createIterator();
};

#endif