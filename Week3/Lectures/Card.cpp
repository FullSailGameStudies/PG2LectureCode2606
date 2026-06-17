#include "Card.h"
#include <iostream>

int Card::Value() const
{
    if (face_ == "A") return 1;
    else if (face_ == "J") return 11;
    else if (face_ == "Q") return 12;
    else if (face_ == "K") return 13;
    else return std::stoi(face_);
}

void Card::Print() const
{
    std::cout << face_ << " of " << suit_;
}
