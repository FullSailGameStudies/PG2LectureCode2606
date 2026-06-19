#include "Knife.h"
#include <iostream>

int Knife::calcDamage()
{
    return Weapon::calcDamage();
}

void Knife::showMe()
{
    Weapon::showMe();
    std::cout << "\tIs Serrated: " << ((isSerrated_) ? "true" : "false") << "\n";
}
