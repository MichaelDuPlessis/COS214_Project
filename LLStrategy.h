#ifndef LLSTRATEGY_H
#define LLSTRATEGY_H

#include <string>
#include <iostream> 
using namespace std;

/** 
 *  @brief     LLStrategy Class
 *  @details   This is the base class for the strategy hierachy
 *  @author    Angela
 *  @date      November 2021
 */
class LLStrategy
{
private:

public:
    //! default constructor
    LLStrategy() {}; 
    //! pure virtual function will be instatiated in concrete strategies
    virtual void launch() = 0; 
    //! pure virtual function will be instatiated in concrete strategies
    virtual void land() = 0; 
};
#endif