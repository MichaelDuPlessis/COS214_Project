#ifndef ROCKET_H
#define ROCKET_H

#include <string>
#include <iostream>

#include "LLStrategy.h"

using namespace std;
/** 
 *  @brief     Rocket Class
 *  @details   This class represents the context participant in the strategy hierachy
 *  @author    Angela
 *  @date      November 2021
 */
class Rocket
{
private:
   LLStrategy* strategy; //!< private member, pointer to a strategy
public:
    //! parameterised constructor
    /*!
        @param s pointer to Strategy
    */
    Rocket(LLStrategy*);
    //! algorithms instatiated in rocket class, same algorithims in strategy classes
    void launch(); 
    //! algorithms instatiated in rocket class, same algorithims in strategy classes
    void land(); 
};
#endif