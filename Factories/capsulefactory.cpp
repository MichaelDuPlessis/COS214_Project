#include "capsulefactory.h"

CapsuleFactory::CapsuleFactory()
{

}

Capsule *CapsuleFactory::buildCapsule()
{
    return new Capsule();
}
