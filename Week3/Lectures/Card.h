#pragma once
#include <string>
class Card
{
public:
	Card(const std::string& face, const std::string& suit)
		: face_(face), suit_(suit)
	{}

	int Value() const;
	void Print() const;

	const std::string& Face() const { return face_; }
	const std::string& Suit() const { return suit_; }

	void Face(const std::string& face)
	{
		if (not face.empty() &&
			(   face == "A" ||face == "2" ||face == "3" ||
				face == "4" ||face == "5" ||face == "6" ||
				face == "7" ||face == "8" ||face == "9" ||
				face == "10" ||face == "J" ||face == "Q" ||
				face == "K"
			))
		{
			face_ = face;
		}
	}
	void Suit(const std::string& suit)
	{
		if (not suit.empty() &&
			suit == "Hearts" || suit == "Diamonds" ||
			suit == "Spades" || suit == "Clubs")
			suit_ = suit;
	}

protected:
	std::string face_, suit_;


};

