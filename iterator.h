#ifndef ITERATOR_H
#define ITERATOR_H

#include "StarlinkSatellite.h"

/**
	*Iterator participant in the iterator design pattern
*/
class Iterator
{
	 public:
	 Iterator();
	 virtual void first() = 0;
	 virtual void next() = 0;
	 virtual StarlinkSatellite* current() = 0; 

};

#endif