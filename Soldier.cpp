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
#include "Soldier.h"
#include <iostream>
using namespace std;
void Soldier::move_position()
{
	int move = rand() % 2;
	//makes the soldier walk 
	if (move == 0 && getStatus() != 0)
	{
		if (getXPosition() < 50)
		{
			setXPosition(getXPosition() + 3);
			cout << "Soldier move to " << getXPosition() << "," << getYPosition() << " ";
		}
		if (getXPosition() >= 50 && getXPosition() <= 750)
		{
			cout << "Soldier move to " << getXPosition() << "," << getYPosition() << " ";
		}
		if (getXPosition() > 750)
		{
			setXPosition(getXPosition() - 3);
			cout << "Soldier move to " << getXPosition() << "," << getYPosition() << " ";
		}
	}
	//makes the soldier run
	if (move == 1 && getStatus() != 0)
	{
		if (getXPosition() < 50)
		{
			setXPosition(getXPosition() + 6);
			cout << "Soldier move to " << getXPosition() << "," << getYPosition() << " ";
		}
		if (getXPosition() >= 50 && getXPosition() <= 750)
		{
			cout << "Soldier move to " << getXPosition() << "," << getYPosition() << " ";
		}
		if (getXPosition() > 750)
		{
			setXPosition(getXPosition() - 6);
			cout << "Soldier move to " << getXPosition() << "," << getYPosition() << " ";
		}
	}
	if (getStatus() == 0)
	{
		cout << " Dead soldier ";
	}
}
//makes the soldier shoot weapon
void Soldier::fire_weapon()
{
	if (ammo != 0 && getStatus() != 0)
	{
		cout << "\nSoldier has fired weapon(" << ammo << " left)\n";
		ammo--;
	}
	if (ammo == 0 && getStatus() != 0)
	{
		cout << "\nSoldier is out of ammo\n";
	}
	if (getStatus() == 0)
	{
		cout << "\nSoldier can't attack because dead.\n";
	}
}
//checks if the soldier has died
void Soldier::update_status()
{
	if (getStatus() == 0)
	{
		cout << "Soldier has been hit. Status points 0 (dead).";
	}
	if (getStatus() >= 0)
	{
		cout << "Soldier update status: hit by bullet, status points" << getStatus() << "(ouch)";
		setStatus(getStatus() - 1);
	}
}