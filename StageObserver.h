#ifndef STAGEOBSERVER_H
#define STAGEOBSERVER_H

#include "Stage.h"
#include <string>

using namespace std;

/**
 * @brief 
 * The class which acts as the Object participant in the Observer design pattern
 * 
 * @class StageObserver
 */
class StageObserver
{

public:
	/**
	 * @brief Construct a new Stage Observer object
	 * 
	 */
	StageObserver(Stage *s);

	/**
	 * @brief Destroy the Stage Observer object
	 * 
	 */
	~StageObserver();

	/**
	 * @brief update state of observed subject
	 * 
	 */
	void update();

private:
	/**
	 * @brief string value of warning message of observed subject
	 * 
	 */
	string warning;

	/**
	 * @brief subject which current observer is observing
	 * 
	 */
	Stage *subject;
};

#endif