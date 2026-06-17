#include "BlackjackCard.h"

int BlackjackCard::Value() const
{
    int value = Card::Value();
    return (value > 10) ? 10 : value;//ternary operator
}
