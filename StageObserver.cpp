#include "StageObserver.h"

#include <iostream>

using namespace std;

StageObserver::StageObserver(){
	cout<<"New StageObserver Created!"<<endl;
}

StageObserver::~StageObserver(){
	cout<<"StageObserver Destroyed!"
}

void StageObserver::update(){
	if(this->subject->getWarning() != this->warning)
		this->warning = this->subject->getWarning();
}