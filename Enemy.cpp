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
#include "Enemy.h"
#include <iostream>
using namespace std;
//parent class virtual functions that get overriden
void Enemy::move_position()
{
	cout << "Enemy has moved positions";
}
void Enemy::fire_weapon()
{
	cout << "Enemy has fired weapon";
}
void Enemy::update_status()
{
	cout << "Status updated";
}
