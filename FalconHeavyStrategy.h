#ifndef FALCONHEAVYSTRATEGY_H
#define FALCONHEAVYSTRATEGY_H

#include <string>
#include "LLStrategy.h"
using namespace std;
/** 
 *  @brief     FalconHeavyStrategy Class
 *  @details   This is the derived class from LLStrategy, it is a concrete Strategy Participant
 *  @author    Angela
 *  @date      November 2021
 */
class FalconHeavyStrategy : public LLStrategy
{
private:

public:
   //! default constructor
    FalconHeavyStrategy();
    //! instatiated algorithm from base class
    void launch();
    //! instatiated algorithm from base class
    void land();
    //! get the name of strategy
    string getKind();
};
#endif
