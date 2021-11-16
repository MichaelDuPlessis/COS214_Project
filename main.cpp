#include "starlinkSatellite.h"
#include "satelliteIterator.h"
#include "network.h"

#include<iostream>

int main()
{
	//simple main used for testing for bugs

	
	StarlinkSatellite** s_list = new StarlinkSatellite*[10];

	for(int i=0; i<10;i++)
		s_list[i] = new StarlinkSatellite(i+1);

	/*for(int i=0; i<10; i++)
		std::cout<<(*s_list[i]).num<<std::endl;*/

	Aggregate* n = new Network();

	for(int i=0;i<10;i++)
		n->addSatellite(s_list[i]);

	Iterator* it = n->createIterator();

	it->first();

	while(it->current() != NULL)
	{
		std::cout<<(it->current())->num<<std::endl;
		it->next();
	}

	for(int i=0; i<10;i++)
		delete s_list[i];

	delete [] s_list;
	return 0;
}