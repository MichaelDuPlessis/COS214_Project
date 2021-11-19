#ifndef NETWORK_H
#define NETWORK_H

#include "aggregate.h"

/**
	*Network class serves as a Concrete aggregate in the iterator pattern
	 as seen from the class diagram.
*/
class Network : public Aggregate
{
	private:
		std::vector<StarlinkSatellite *> satellites;
	public:
		std::vector<int> test;
		Network();
		~Network();
		Iterator* createIterator();
		
		int getSize();
		std::vector<StarlinkSatellite*> getSatellites();
	 	void addSatellite(StarlinkSatellite*);
		void clear();
};

#endif