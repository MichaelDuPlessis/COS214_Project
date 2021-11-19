#include "Dragon.h"

Dragon::Dragon() : Capsule("Dragon") {}

Dragon::~Dragon() {}

void Dragon::unloadContents()
{
    std::cout << "Unloading cargo from Dragon capsule\n";
}

