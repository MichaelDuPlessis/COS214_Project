/*
	Completed By: 
		Name: Jonah Gasura
		Student Number: 20592061

*/

#include "Thruster.h"

#include <iostream>

using namespace std;

Thruster::Thruster()
{
	cout << "New Thruster Created!" << endl;
}

Thruster::~Thruster()
{
	cout << "Thruster Destroyed!" << endl;
}

void Thruster::fire()
{
	cout << "Thruster fired!" << endl;
}

void Thruster::add(Thruster *thruster)
{
}

void Thruster::remove(Thruster *thruster)
{
}

void Thruster::getChild(int pos)
{
}