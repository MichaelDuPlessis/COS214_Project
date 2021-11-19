#ifndef SATELLITEITERATOR_H
#define SATELLITEITERATOR_H

#include "iterator.h"
#include<vector>

/**
	*Concrete iterator participant
*/
class SatelliteIterator : public Iterator
{
	 public:
	 	SatelliteIterator(std::vector<StarlinkSatellite*> );
		void first();
		void next();
		StarlinkSatellite* current();
	private:
		std::vector<StarlinkSatellite*> list;
		int currentPos;

};
#endif