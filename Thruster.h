/*
	Completed By: 
		Name: Jonah Gasura
		Student Number: 20592061

*/		

#ifndef THRUSTER_H
#define THRUSTER_H

using namespace std;

class Thruster
{

public:
	Thruster();

	virtual ~Thruster();

	virtual void fire();

	virtual void add(Thruster* thruster);

	virtual void remove(Thruster* thruster);

	virtual void getChild(int pos);

	
};

#endif