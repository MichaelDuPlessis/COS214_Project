#include "../Crew.h"
#include "../CrewDragon.h"
#include "gtest/gtest.h"

namespace {
    //Tests addCrew()

    /**
     * @brief Construct a new TEST object to test that true is returned when crew members are added while the crew dragon has space
     * 
     */
    TEST(AddCrewTest, SpaceInDragon)
    {
        /**
         * @brief Unit Test for adding of crew members onto crew dragon capsule
         * 
         */

        Crew **crewMembers1 = new Crew *[10];

        for (int i = 0; i < 10; i++)
        {
            crewMembers1[i] = new Crew("TestCrewMember", "TestSpecialisation");
        }

        CrewDragon *cd1 = new CrewDragon();

        /**
         * @brief Expect true to be returned 8 times
         * 
         */
        for (int j = 0; j < 8; j++)
        {
            EXPECT_TRUE(cd1->addCrew(crewMembers1[j]));
        }
    }

    /**
     * @brief Construct a new TEST object to test that false is returned when crew members are added while the crew dragon has no space
     * 
     */
    TEST(AddCrewTest, NoSpaceInDragon)
    {
        /**
         * @brief Unit Test for adding of crew members onto crew dragon capsule
         */

        Crew **crewMembers2 = new Crew *[10];

        for (int i = 0; i < 10; i++)
        {
            crewMembers2[i] = new Crew("TestCrewMember", "TestSpecialisation");
        }

        CrewDragon *cd2 = new CrewDragon();

        /**
         * @brief Expect false to be returned 2 times
         * 
         */
        for (int k = 0; k < 8; k++)
        {
            cd2->addCrew(crewMembers2[k]);
        }

            EXPECT_FALSE(cd2->addCrew(crewMembers2[8]));
            EXPECT_FALSE(cd2->addCrew(crewMembers2[9]));
    }
}
