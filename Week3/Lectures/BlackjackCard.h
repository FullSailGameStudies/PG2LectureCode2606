#pragma once
#include "Card.h"
class BlackjackCard : public Card
{
public:
	BlackjackCard(const std::string& face, const std::string& suit) :
		Card(face, suit)
	{		
	}

	int Value() const override;
};

