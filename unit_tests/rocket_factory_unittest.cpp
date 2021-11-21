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
    * @details check that the rocket factory builds falcon 9s and falconheavies
    * 
    */
    TEST(RocketFactoryTest, FalconBuildTest)
    {
        RocketFactory* rf = new RocketFactory();
        try
        {    

            Rocket* r = rf->buildFalcon9("TestRocket9", true);
            EXPECT_TRUE(typeid(*rf)==typeid(Rocket));
            Stage* s = r->getStages().at(0);
            delete rf;

        }
        catch(...){
            FAIL();
        }
    }
}