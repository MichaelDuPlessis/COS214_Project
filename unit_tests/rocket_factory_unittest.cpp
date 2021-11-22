#include "../Factories/rocketfactory.h"
#include "gtest/gtest.h"

namespace
{
    /**
    * @brief Null Factories test
    * @details test what happens when Rocket Factories interanl factories arent set 
    * 
    */
    TEST(RocketFactoryTest, buildingWithNullFactories)
    {

        RocketFactory* rf = new RocketFactory(NULL, NULL, NULL);
        try
        {    

            delete rf->buildFalcon9("TestRocket9", true);
            delete rf->buildFalconHeavy("TestRocketHeavy", true);
            delete rf;

            SUCCEED();
        }
        catch(...)
        {
            FAIL();
        }

    }

    /**
    * @brief build falcon 9 test
    * @details check that the rocket factory builds falcon 9s
    * 
    */
    TEST(RocketFactoryTest, Falcon9BuildTest)
    {
        RocketFactory* rf = new RocketFactory();
        try
        {    

            Rocket* r = rf->buildFalcon9("TestRocket9", true);
            EXPECT_TRUE(typeid(*rf)==typeid(Rocket));
            Stage* s = r->getStages().at(0);

            EXPECT_EQ(1, s->getNumThrusters());
            delete rf;

        }
        catch(...){
            FAIL();
        }
    }

    /**
    * @brief build falcon heavy test
    * @details check that the rocket factory builds falcon heavies
    * 
    */
    TEST(RocketFactoryTest, FalconHeavyBuildTest)
    {
        RocketFactory* rf = new RocketFactory();
        try
        {    

            Rocket* r = rf->buildFalcon9("TestRocketHeavy", false);
            EXPECT_TRUE(typeid(*r)==typeid(Rocket));
            Stage* s = r->getStages().at(0);

            EXPECT_EQ(3, s->getNumThrusters());
            delete rf;

        }
        catch(...){
            FAIL();
        }
    }

        /**
    * @brief build capsules
    * @details check that the rocket factory can build the correct capsules
    * 
    */
    TEST(RocketFactoryTest, CapsuleBuildTest)
    {
        RocketFactory* rf = new RocketFactory();
        try
        {    

            Capsule* c1= rf->builldCapsule(true);
            Capsule* c2= rf->builldCapsule(false);

            EXPECT_TRUE(typeid(*c1)==typeid(CrewDragon));
            EXPECT_TRUE(typeid(*c2)==typeid(Dragon));

            delete c1;
            delete c2;
            delete rf;

        }
        catch(...){
            FAIL();
        }
    }
}