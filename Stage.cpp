#include "Stage.h"

#include <iostream>

using namespace std;

Stage::Stage(){
	cout<<"New Stage Created!"<<endl;
}

Stage::~Stage(){
	cout<<"Stage Destroyed!"
}

void Stage::startStage(){
	cout<<"Stage started!"<<endl;
}

void Stage::stopStage(){
	cout<<"Stage stopped!"<<endl;
}

string Stage::getWarning(){
	return this->warning;
}

void Stage::setWarning(string w){
	this->warning = w;
}

void Stage::detach(StageObserver* obs){
	vector<StageObserver*>::iterator it;

	for(it = stageObservers.begin(); it < stageObservers.end(); it++){
		if(*it == obs)
			this->stageObservers.erase(it--);
	}
}

void Stage::attach(StageObserver* obs){
	this->stageObservers.push_back(obs);
}

void Stage::land(){
	cout<<"Landed"<<endl;
}

//additional - NOT IN THE CLASS DIAGRAM

void notify(){
	vector<StageObserver*>::iterator it;

	for(it = stageObservers.begin(); it < stageObservers.end(); it++){
		(*it)->update();
	}
}