#pragma once
#include "Weapon.h"
//the class relationship
//in OOP, it is called the IS-A relationship
class Pistol : public Weapon
{
public:

	//the derived ctor MUST call
	// a base ctor
	//do NOT duplicate what the base does
	//call the base ctor
	Pistol(int ammo, int capacity, int range, int damage) :
		//use the member initialization list to call
		//the base ctor
		Weapon(range, damage),
		ammo_(ammo), capacity_(capacity)
	{}

	int Ammo() const { return ammo_; }
	int Capacity() const { return capacity_; }
	void Ammo(int ammo)
	{
		if (ammo >= 0 && ammo <= capacity_)
			ammo_ = ammo;
	}
	void Capacity(int cap)
	{
		if (cap > 0 && cap < 30)
		{
			capacity_ = cap;
		}
	}

private:
	int ammo_, capacity_;
};

