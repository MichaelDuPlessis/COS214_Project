#include "../Factories/thrusterfactory.h"
#include "gtest/gtest.h"

namespace
{
    /** * @brief Create VacuumMerlin */
    TEST(ThrustertFactoryTest, buildVacuumMerlin)
    {
        ThrusterFactory* f = new ThrusterFactory();
        try
        {    

            Thruster* t = f->createVaccumeThruster();
            EXPECT_TRUE(typeid(*t)==typeid(Vacuum));

            delete t;
            delete f;

        }
        catch(...){
            FAIL();
        }
    }

    /** * @brief Create FalconCore */
    TEST(ThrustertFactoryTest, buildFaclonCore){
        ThrusterFactory* f = new ThrusterFactory();
        try
        {    

            Thruster* t = f->createCoreThruster();
            EXPECT_TRUE(typeid(*t)==typeid(FalconCore));
            vector<Thruster*> thrusters = ((FalconCore*) t)->getThursters();
            EXPECT_EQ(9, thrusters.size());
            
            for (vector<Thruster*>::iterator itr = thrusters.begin(); itr != thrusters.end(); itr++)  
                EXPECT_TRUE(typeid((*itr))==typeid(Merlin));
            
            delete t;
            delete f;

        }
        catch(...){
            FAIL();
        }
    }


}