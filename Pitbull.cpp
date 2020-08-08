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
#include "Pitbull.h"
#include <iostream>
#include <cstdlib> 
using namespace std;
//moves the position of the pitbull
void Pitbull::move_position()
{
	int move = rand() % 2;
	//implements the walking part of the pitbull
	if (move == 0 && getStatus() != 0)
	{
		if (getXPosition() < 50)
		{
			setXPosition(getXPosition() + 3);
			cout << "Pitbull move to " << getXPosition() << "," << getYPosition() << " ";
		}
		if (getXPosition() >= 50 && getXPosition() <= 750)
		{
			cout << "Pitbull move to " << getXPosition() << "," << getYPosition() << " ";
		}
		if (getXPosition() > 750)
		{
			setXPosition(getXPosition() - 3);
			cout << "Pitbull move to " << getXPosition() << "," << getYPosition() << " ";
		}
	}
	//implements the running part of the pitbull
	if (move == 1 && getStatus() != 0)
	{
		if (getXPosition() < 50)
		{
			setXPosition(getXPosition() + 6);
			cout << "Pitbull move to " << getXPosition() << "," << getYPosition() << " ";
		}
		if (getXPosition() >= 50 && getXPosition() <= 750)
		{
			cout << "Pitbull move to " << getXPosition() << "," << getYPosition() << " ";
		}
		if (getXPosition() > 750)
		{
			setXPosition(getXPosition() - 6);
			cout << "Pitbull move to " << getXPosition() << "," << getYPosition() << " ";
		}
	}
	//doesn't move if dead
	if (getStatus() == 0)
	{
		cout << " Dead pitbull ";
	}
}
//fires weapon of pitbull
void Pitbull::fire_weapon()
{
	//makes a random choice of attack
	int num = rand() % 3;
	if (num == 0 && getStatus() != 0)
	{
		cout << "\nPitbull has bitten leg\n";
	}
	if (num == 1 && getStatus() != 0)
	{
		cout << "\nPitbull has slashed chest\n";
	}
	if (num == 2 && getStatus() != 0)
	{
		cout << "\nPitbull has bitten neck\n";
	}
	if (getStatus() == 0)
	{
		cout << "\nPitbull can't attack because dead\n";
	}
}
//updates the lives of pitbull
void Pitbull::update_status()
{
	if (getStatus() == 0)
	{
		cout << "Pitbull has been hit. Status points 0 (dead).";
	}
	if (getStatus() >= 1)
	{
		cout << "Pitbull update status: hit by bullet, status points" << getStatus() << "(bark)";
		setStatus(getStatus() - 1);
	}
}
