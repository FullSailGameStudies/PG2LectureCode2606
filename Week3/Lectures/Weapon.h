#pragma once
class Weapon
{
private:
	int mRange;
	int mDamage;

public:
	Weapon() : mRange(0), mDamage(0) {}
	Weapon(int range, int damage);

	//OVERRIDING:
	//STEP 1: mark the base method as 'virtual'
	//   TIP: ONLY mark the methods in the base that need overridden
	//		don't mark every method as virtual
	//   this tells the compiler and runtime that
	//		the derived classes MIGHT have overridden it
	virtual void showMe();
	
	//make this method a pure virtual
	//to make the class an ABSTRACT base class
	virtual int calcDamage() = 0;

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}
};

