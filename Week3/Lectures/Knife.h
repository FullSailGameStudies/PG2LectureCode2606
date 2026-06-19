#pragma once
#include "Weapon.h"
class Knife :
    public Weapon
{
public:

    Knife(bool isSerrated, int range, int damage)
        : Weapon(range,damage),
        isSerrated_(isSerrated)
    {
    }
    bool IsSerrated() const { return isSerrated_; }
    void IsSerrated(bool isSerrated)
    {
        isSerrated_ = isSerrated;
    }
    int calcDamage() override;
    void showMe() override;

private:
    bool isSerrated_;
};

