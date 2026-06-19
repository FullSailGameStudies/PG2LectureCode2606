#pragma once
#include "Weapon.h"
#include <algorithm>
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

	Pistol operator+(const Pistol& other)
	{
		int newAmmo = ammo_ + other.ammo_;
		int newCap = std::max(capacity_, other.capacity_);
		Pistol result(newAmmo, newCap, range(), damage());
		return result;
	}

	//override the pure virtual to make sure
	//this class is also NOT an abstract base class
	int calcDamage() override;

	//OVERRIDE:
	//STEP 2:
	// create another method in the derived that
	// matches the base (return type, name, parameters).
	// OPTIONAL (but good). add the 'override' keyword
	void showMe() override;

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
	//HAS-A relationship
	int ammo_, capacity_;


	//
	// favor HAS-A over IS-A
	// HAS-A can be changed at runtime
};

