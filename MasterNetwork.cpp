#include <iostream>

#include "MasterNetwork.h"

using namespace std;

Network* MasterNetwork::nw;

MasterNetwork::MasterNetwork(){
    nw = new Network();
}


MasterNetwork::~MasterNetwork(){
	delete nw;
}

MasterNetwork* MasterNetwork::singleton = 0;

int MasterNetwork::nextId;

int MasterNetwork::getID() { return nextId++; }

MasterNetwork* MasterNetwork::instance() {
  if(singleton == 0) {
	  singleton = new MasterNetwork();
      nextId = 0;
  }
  return singleton;
}

Network* MasterNetwork::network() 
{
    return nw;
}

void MasterNetwork::clearNetwork() 
{
    delete nw;
    nw = new Network();
}

void MasterNetwork::communicate(){
    Iterator * it = nw->createIterator();
    for (it->first(); !it->end(); it->next())
    {   
        it->current()->communicateGround();
        it->current()->communicateSatellite();
    }

    delete it;
}