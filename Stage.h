#ifndef STAGE_H
#define STAGE_H

#include "thruster.h"

class StageObserver;

#include <string>
#include <vector>

/**
 * @brief 
 * The class which acts as the Subject participant in the Observer design pattern
 * 
 * @class Stage
 */

using namespace std;

class Stage
{

public:
	/**
	 * @brief Construct a new Stage object
	 * 
	 */
	Stage(Thruster *t);

	/**
	 * @brief Destroy the Stage object
	 * 
	 */
	~Stage();

	/**
	 * @brief Start current stage
	 * 
	 */
	void startStage();

	/**
	 * @brief Stop current stage
	 * 
	 */
	void stopStage();

	/**
	 * @brief Get the Warning message for current stage
	 * 
	 * @return string 
	 */
	string getWarning();

	/**
	 * @brief Set the Warning message for current stage
	 * 
	 * @param[in]	w	The new message to be used to update current warning message 
	 */
	void setWarning(string w);

	/**
	 * @brief Remove specific observer from observerList of this stage (Subject)
	 * 
	 * @param[in]	obs The observer that must be removed 
	 */
	void detach(StageObserver *obs);

	/**
	 * @brief Add specific observer to the observerList of this stage (Subject)
	 * 
	 * @param[in]	obs The observer that must be added  
	 */
	void attach(StageObserver *obs);

	/**
	 * @brief Land current stage
	 * 
	 */
	void land();

	//additional
	/**
	 * @brief Notify all observers when change has occurred (warning message has been updated)
	 * 
	 */
	void notify();

private:
	/**
	 * @brief Thruster object
	 * 
	 */
	Thruster *thruster;

	/**
	 * @brief String to indicate current warning status of the current stage
	 * 
	 */
	string warning;

	/**
	 * @brief Vector object representing observer list for current stage object
	 * 
	 */
	vector<StageObserver *> stageObservers;
};

#endif