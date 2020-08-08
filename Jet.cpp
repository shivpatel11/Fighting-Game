/***************************************************************
*file: Main.cpp
*author: Shiv Patel
*class: CS 2560 – C++
*assignment: program 6
*date last modified: 12/6/19
*
*purpose: This program simulates a enemy list and it continues until there is one enemy left
*
****************************************************************/
#include "Jet.h"
#include <iostream>
using namespace std;
//moves position of jet
void Jet::move_position()
{
	int move = rand() % 2;
	//makes the jet speed up slow
	if (move == 0 && getStatus() != 0)
	{
		if (getXPosition() < 50)
		{
			setXPosition(getXPosition() + 15);
			cout << "Jet move to " << getXPosition() << "," << getYPosition() << " ";
		}
		if (getXPosition() >= 50 && getXPosition() <= 750)
		{
			cout << "Jet move to " << getXPosition() << "," << getYPosition() << " ";
		}
		if (getXPosition() > 750)
		{
			setXPosition(getXPosition() - 15);
			cout << "Jet move to " << getXPosition() << "," << getYPosition() << " ";
		}
	}
	//makes the jet speed up fast
	if (move == 1 && getStatus() != 0)
	{
		if (getXPosition() < 50)
		{
			setXPosition(getXPosition() + 30);
			cout << "Jet move to " << getXPosition() << "," << getYPosition() << " ";
		}
		if (getXPosition() >= 50 && getXPosition() <= 750)
		{
			cout << "Jet move to " << getXPosition() << "," << getYPosition() << " ";
		}
		if (getXPosition() > 750)
		{
			setXPosition(getXPosition() - 30);
			cout << "Jet move to " << getXPosition() << "," << getYPosition() << " ";
		}
	}
	//doesn't move if dead
	if (getStatus() == 0)
	{
		cout << " Dead Jet ";
	}
}
//jet fires missile
void Jet::fire_weapon()
{
	if (ammo != 0 && getStatus() != 0)
	{
		cout << "\nJet has fired missile(" << ammo << " left)\n";
		ammo--;
	}
	if (ammo == 0 && getStatus() != 0)
	{
		cout << "\nJet is out of ammo";
	}
	if (getStatus() == 0)
	{
		cout << "\nJet can't attack because dead\n";
	}
}
//checks if jet dies
void Jet::update_status()
{
	if (getStatus() == 0)
	{
		cout << "Jet has been hit. Status points 0 (dead).";
	}
	if (getStatus() >= 0)
	{
		cout << "Jet update status: hit by bullet, status points" << getStatus() << "(ping)";
		setStatus(getStatus() - 1);
	}
}