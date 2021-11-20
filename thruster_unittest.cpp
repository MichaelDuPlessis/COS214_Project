#include "thruster.h"
#include "FalconCore.h"
#include "Merlin.h"
#include "gtest/gtest.h"

namespace {
    //Tests addThruster()

    //Tests that more than one engine can't be added to a Thruster
    //Testing the postcondition: Check that function returns false when engine is already added to Thruster
    TEST(AddThrusterTest, Negative) {
    //this test belongs to the AddThrusterTest case.
    try {
        FalconCore* thruster = new FalconCore();
        Merlin* merlinEngine = new Merlin();

        thruster->addThruster(merlinEngine);
        thruster->addThruster(merlinEngine);
        FAIL();

    } catch(...) {
        FAIL();
    }
    }


    
}