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
#include <conio.h>
#include <iostream>
#include "Enemy.h"
#include "Jet.h"
#include "Soldier.h"
#include "Pitbull.h"
#include <cstdlib>
using namespace std;
int main(int argc, char* argv[])
{
	//create array for enemies
	const int max_enemy = 20;
	Enemy* enemy_ptr[max_enemy];
	int second_array[max_enemy];
	enemy_ptr[0] = new Jet(rand() % 800, 200, 5, 4, 7);
	second_array[0] = 1;
	// set value of num_enemy randomly between 3 and 20
	int num_enemy = rand() % 17 + 3;
	int totalEnemies = num_enemy;
	// create Enemy objects, place in array
	for (int i = 0; i < num_enemy; i++)
	{
		int enemy = rand() % 3;
		if (enemy == 0)
		{
			enemy_ptr[i] = new Jet(rand() % 800, 200, 5, 4, 7);
			second_array[i] = 1;
		}
		if (enemy == 1)
		{
			enemy_ptr[i] = new Soldier(rand() % 800, 500, 1, 3, 4);
			second_array[i] = 1;
		}
		if (enemy == 2)
		{
			enemy_ptr[i] = new Pitbull(rand() % 800, 500, 1, 1, 1);
			second_array[i] = 1;
		}
	}
	bool running = true;
	while (running) {
		//every Enemy object should move_position
		for (int i = 0; i < totalEnemies; i++)
		{
			enemy_ptr[i]->move_position();
		}
		// Pick a random Enemy to fire_weapon
		int randomFire = rand() % totalEnemies;
		if (randomFire < 0) randomFire = 0;

		while (enemy_ptr[randomFire]->getStatus() == 0)
		{
			randomFire++;
			if (randomFire >= totalEnemies)
			{
				randomFire = 0;
			}
		}
		enemy_ptr[randomFire]->fire_weapon();
		// Pick a random Enemy to update_statusgetch();
		int randomStatus = rand() % totalEnemies;
		if (randomStatus < 0) randomStatus = 0;

		while (enemy_ptr[randomStatus]->getStatus() == 0)
		{
			randomStatus++;
			if (randomStatus >= totalEnemies)
			{
				randomStatus = 0;
			}
		}
		//update the second array to check for dead enemies
		enemy_ptr[randomStatus]->update_status();
		if (enemy_ptr[randomStatus]->getStatus() < 1)
		{
			second_array[randomStatus] = 0;
		}
		//counts how many enemies are alive
		num_enemy = 0;
		for (int i = 0; i < totalEnemies; i++)
		{
			if (second_array[i] == 1)
			{
				num_enemy++;
			}
		}
		cout << endl << endl;
		if (num_enemy <= 1)
		{
			running = false;
			break;
		}
	}
	cout << endl << "Total Enemies Left: " << num_enemy;
	return 0;
}

