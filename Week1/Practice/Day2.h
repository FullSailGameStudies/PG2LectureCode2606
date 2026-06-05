#pragma once
#include <vector>
#include "Target.h"
#include "Map.h"
#include "Zombie.h"
#include "Player.h"

class Day2
{
public:

	void PartB(int option = 1);

	void NumberOfDays() const
	{
		//can't change the object
		//can't call other non-const methods of the class
		//days = 100;
		//SpawnZombies();
		//std::cout << days;
	}

	void PrintMe(const std::vector<int>& numbers, int top = 0);
private:

	int days;
	//
	// Part B-1.1: Add a method declaration for SpawnZombies
	//
	void SpawnZombies(PG2Graphics& graphics, std::vector<Zombie>& walkers,const Player& steev) const;

	//
	// Part B-2.1: Add a method declaration for RenderZombies
	//
	void RenderZombies(const std::vector<Zombie>& walkers)const;

	//
	// Part B-3.1: Add a method declaration for KillZombies
	//
	int KillZombies(std::vector<Zombie>& walkers,const Player& player) const;

};

