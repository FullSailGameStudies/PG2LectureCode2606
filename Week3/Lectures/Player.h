#pragma once

//only #include the files THIS file needs to compile
#include <string>

class Player
{
	//ACCESS modifiers - determine the visiblity outside of the class
	//public - ALL code can see it
	//private (default) - *only this class can see it
	//   * - there are ways around it
	//protected - my class and all descendents of my class can see it
	//
	// you can have as many of these sections as you want and in any order

	//in general, hide as much as you can

private:

	//FIELDS (data member or member variables)
	//  what describes the object
	//  in general (most of the time), make your fields private
	// naming conventions
	//	  camelCasingNamingConvention
	//	  for fields, we usually add something extra
	//	  to set it apart from other variables
	//	  EX: m_sGamerTag, m_wsGamerTag, m_gamerTag, mGamerTag, _gamerTag, gamerTag_
	//	  if it's a public field, make it as simple as possible
	std::string gamerTag_;
	int health_;

	//getters/setters (gatekeepers) - methods used to access and modify fields
	//   most of the time we define them in the header
	//	 why? the compiler can optimize their usage and make it faster
	//getters (accessors) 
	//  usually const
	//  usually no parameters
	//  return type matches the type of the field
	const std::string& GetGamerTag() const
	{
		return gamerTag_;
	}
	//alternate naming
	int Health() const { return health_; }

	//setters (mutators)
	//  no return type
	//  can't be const
	//  usually has a parameter that 
	//   matches the type of the field
	//  can have validation on the parameter
	//		before using it
	void SetGamerTag(const std::string& newGamerTag)
	{
		//add some validation before accepting the parameter
		if (not newGamerTag.empty() and newGamerTag.size() <= 25)
		{
			gamerTag_ = newGamerTag;
		}
	}
	void Health(int updatedHealth)
	{
		if (updatedHealth >= 0 && updatedHealth <= 100)
			health_ = updatedHealth;
	}
};

