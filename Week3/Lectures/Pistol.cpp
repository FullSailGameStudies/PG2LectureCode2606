#include "Pistol.h"
#include <iostream>

void Pistol::showMe()
{
	//2 modes of overriding:
	//  FULL OVERRIDE
	//		ONLY want the new behavior
	//  EXTENSION OVERRIDE
	//		want the base behavior + the new behavior
	//		do NOT duplicate what the base does. call the base.
	Weapon::showMe();
	std::cout << "\tAmmo: " << ammo_ << " Capacity: " << capacity_ << "\n";
}
