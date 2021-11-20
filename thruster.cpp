#include "thruster.h"


Thruster::~Thruster() {}

//THIS CODE SHOULD NEVER BE CALLED
//returns true if thurster added succesfully, false if not, return flase if adding thurster already exist
//eg make thurster
//create 2 merlin egines, add one to thurster (return true), ad another should treutn falde
bool Thruster::addThruster(Thruster*) { return true;    }

//THIS CODE SHOULD NEVER BE CALLED
bool Thruster::removeThruster(Thruster*) {  return true;  }