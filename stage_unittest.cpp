#include "Stage.h"
#include "StageObserver.h"
#include "gtest/gtest.h"

namespace {
    //Tests update()

    Stage* stage = new Stage();
    StageObserver* obs = new StageObserver(stage);


    //Tests that correct warning is returned from StageObserver
    //Testing the postcondition: Check that function returns different warning message
    TEST(UpdateTest, Negative) {
    //this test belongs to the AddThrusterTest case.
    try {
        //go to observer->getWarning()
        //check that this warning matches passed in warning
        stage->attach(obs);
        stage->setWarning("Warning");
        stage->notify();
        EXPECT_EQ("none", obs->getWarning());
        FAIL();

    } catch(...) {
        FAIL();
    }
    }

    //Tests positive result
    TEST(UpdateTest, Positive) {
        stage->attach(obs);
        stage->setWarning("Warning");
        stage->notify();
        EXPECT_EQ("Warning", obs->getWarning());
    }
}