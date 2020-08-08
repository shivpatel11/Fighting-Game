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
#pragma once
#include "Enemy.h"
using namespace std;
class Pitbull : public Enemy
{
	//constructor for pitbull
	public:
		Pitbull(double x, double y, double w, double h, double s) : Enemy(x, y, w, h, s)
		{

		}
		virtual void move_position();
		virtual void fire_weapon();
		virtual void update_status();
};

