#pragma once
class Card
{
public:
	enum Suit {
		HEARTS,
		CLUBS,
		SPADES,
		DIAMONDS
	};
	Suit suit() const;
	int value() const;
	Card(int cardValue, Suit suitValue);
	bool Valid() const;
	
	
private:
	Suit _suit;
	int _value;
};

