#include "Stage.h"
#include "Falcon9Strategy.h"
#include "CrewDragon.h"
#include "Rocket.h"
#include <vector>
#include "gtest/gtest.h"

namespace
{
    /**
    * @brief Construct a new TEST object to test that false is returned when warning updated for a stage - invalid position entered
    * 
    */
    TEST(RocketTest, setWarningInvalidPos)
    {
        /**
         * @brief Unit Test for setting a stage warning, updating stage observers and determining whether rocket can proceed with launching 
         * 
         */

        Stage *s1 = new Stage();
        Stage *s2 = new Stage();

        vector<Stage *> stageList;

        stageList.push_back(s1);
        stageList.push_back(s2);

        LLStrategy *str = new Falcon9Strategy();
        Capsule *c = new CrewDragon();

        Rocket *r = new Rocket(str, c, stageList, "TestRocket");

        /**
         * @brief Expect false to be returned
         * 
         */

        EXPECT_FALSE(r->setStageWarning("minor", 50));
        EXPECT_FALSE(r->setStageWarning("major", -1));
    }

    /**
    * @brief Construct a new TEST object to test that true is returned when warning updated for a stage - valid position entered
    * 
    */
    TEST(RocketTest, setWarningValidPos)
    {
        /**
         * @brief Unit Test for setting a stage warning, updating stage observers and determining whether rocket can proceed with launching 
         * 
         */

        Stage *s1 = new Stage();
        Stage *s2 = new Stage();

        vector<Stage *> stageList;

        stageList.push_back(s1);
        stageList.push_back(s2);

        LLStrategy *str = new Falcon9Strategy();
        Capsule *c = new CrewDragon();

        Rocket *r = new Rocket(str, c, stageList, "TestRocket");

        /**
         * @brief Expect true to be returned
         * 
         */

        EXPECT_TRUE(r->setStageWarning("minor", 0));
        EXPECT_TRUE(r->setStageWarning("major", 1));
    }

    /**
    * @brief Construct a new TEST object to test that false is returned when observers notified - invalid position entered
    * 
    */
    TEST(RocketTest, notifyInvalidPos)
    {
        /**
         * @brief Unit Test for setting a stage warning, updating stage observers and determining whether rocket can proceed with launching 
         * 
         */

        Stage *s1 = new Stage();
        Stage *s2 = new Stage();

        vector<Stage *> stageList;

        stageList.push_back(s1);
        stageList.push_back(s2);

        LLStrategy *str = new Falcon9Strategy();
        Capsule *c = new CrewDragon();

        Rocket *r = new Rocket(str, c, stageList, "TestRocket");

        /**
         * @brief Expect false to be returned
         * 
         */

        EXPECT_FALSE(r->updateStageObs(65));
        EXPECT_FALSE(r->updateStageObs(-1));
    }

    /**
    * @brief Construct a new TEST object to test that false is returned when observers notified - invalid position entered
    * 
    */
    TEST(RocketTest, notifyValidPos)
    {
        /**
         * @brief Unit Test for setting a stage warning, updating stage observers and determining whether rocket can proceed with launching 
         * 
         */

        Stage *s1 = new Stage();
        Stage *s2 = new Stage();

        vector<Stage *> stageList;

        stageList.push_back(s1);
        stageList.push_back(s2);

        LLStrategy *str = new Falcon9Strategy();
        Capsule *c = new CrewDragon();

        Rocket *r = new Rocket(str, c, stageList, "TestRocket");

        /**
         * @brief Expect true to be returned
         * 
         */

        r->setStageWarning("major", 0);
        r->setStageWarning("minor", 1);

        EXPECT_TRUE(r->updateStageObs(0));
        EXPECT_TRUE(r->updateStageObs(1));
    }

    /**
    * @brief Construct a new TEST object to test that false is returned when checking if rocket can launch when warning exists on stage
    * 
    */
    TEST(RocketTest, cantLaunch)
    {
        /**
         * @brief Unit Test for setting a stage warning, updating stage observers and determining whether rocket can proceed with launching 
         * 
         */

        Stage *s1 = new Stage();
        Stage *s2 = new Stage();

        vector<Stage *> stageList;

        stageList.push_back(s1);
        stageList.push_back(s2);

        LLStrategy *str = new Falcon9Strategy();
        Capsule *c = new CrewDragon();

        Rocket *r = new Rocket(str, c, stageList, "TestRocket");

        /**
         * @brief Expect false to be returned
         * 
         */

        r->setStageWarning("major", 0);
        EXPECT_FALSE(r->canLaunch());
    }

    /**
    * @brief Construct a new TEST object to test that true is returned when checking if rocket can launch when no warning exists on stage
    * 
    */
    TEST(RocketTest, canLaunch)
    {
        /**
         * @brief Unit Test for setting a stage warning, updating stage observers and determining whether rocket can proceed with launching 
         * 
         */

        Stage *s1 = new Stage();
        Stage *s2 = new Stage();

        vector<Stage *> stageList;

        stageList.push_back(s1);
        stageList.push_back(s2);

        LLStrategy *str = new Falcon9Strategy();
        Capsule *c = new CrewDragon();

        Rocket *r = new Rocket(str, c, stageList, "TestRocket");

        /**
         * @brief Expect true to be returned
         * 
         */

        r->setStageWarning("none", 0);
        r->setStageWarning("none", 1);
        EXPECT_TRUE(r->canLaunch());
    }
}