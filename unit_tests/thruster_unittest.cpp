#include "../thruster.h"
#include "../FalconCore.h"
#include "../merlin.h"
#include "gtest/gtest.h"

namespace {
    //Tests addThruster()

    FalconCore* thruster = new FalconCore();
    Merlin* merlinEngine = new Merlin();

    //Tests that the same merlin engine can't be added to a singular Thruster
    //Testing the postcondition: Check that function returns false when engine is already added to Thruster
    TEST(AddThrusterTest, Negative) {
    //this test belongs to the AddThrusterTest case.
    try {
        thruster->addThruster(merlinEngine);
        thruster->addThruster(merlinEngine);
        FAIL();

    } catch(...) {
        FAIL();
    }
    }

    //Tests positive result
    TEST(AddThrusterTest, Positive) {
        EXPECT_TRUE(thruster->addThruster(new Merlin()));
    }


    
}