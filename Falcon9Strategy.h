#ifndef FALCON9STRATEGY_H
#define FALCON9STRATEGY_H

#include <string>
#include "LLStrategy.h"
using namespace std;
/** 
 *  @brief     Falcon9Strategy Class
 *  @details   This is the derived class from LLStrategy, it is a concrete Strategy Participant
 *  @author    Angela
 *  @date      November 2021
 */
class Falcon9Strategy : public LLStrategy
{
private:

public:
   //! default constructor
    Falcon9Strategy();
    //! instatiated algorithm from base class
    void launch();
    //! instatiated algorithm from base class
    void land();
    //! get the name of the strategy
    string getKind();
};
#endif