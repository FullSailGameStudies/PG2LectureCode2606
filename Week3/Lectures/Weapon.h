#pragma once
class Weapon
{
private:
	int mRange;
	int mDamage;

public:
	Weapon() : mRange(0), mDamage(0) {}
	Weapon(int range, int damage);

	virtual void showMe();
	int calcDamage();

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}
};

