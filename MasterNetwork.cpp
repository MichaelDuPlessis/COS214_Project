#include <iostream>

#include "MasterNetwork.h"

using namespace std;

MasterNetwork::MasterNetwork(){
    nw = new Network();
}


MasterNetwork::~MasterNetwork(){
	delete nw;
}

MasterNetwork* MasterNetwork::singleton = 0;

MasterNetwork* MasterNetwork::instance() {
  if(singleton == 0) {
	  singleton = new MasterNetwork();
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