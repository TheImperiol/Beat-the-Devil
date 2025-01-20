#include "CardInterface.h"



Card::Suit Card::suit() const
{
    return _suit;
}

int Card::value() const
{
    return _value;
}

Card::Card(int cardValue, Suit suitValue)
{
    _value = cardValue; 
    _suit = suitValue;
}

bool Card::Valid() const
{
    if (value() >= 1 && value() <= 13) {
        return true;
    }
    else {
        return false;
    }
}
