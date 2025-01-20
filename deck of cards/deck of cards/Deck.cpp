#include "Deck.h"

void Deck::AddElement(Card card)
{
	deck->push(card);
}

Card Deck::TakeCard()
{
	Card selected = deck->front();
	deck->pop();
	
	return selected;
}

void Deck::DecreaseNumOfSuit(Card::Suit _suit)
{
	if (_suit == Card::CLUBS) {
		numOfClubs--;
	}
	else if (_suit == Card::HEARTS) {
		numOfHearts--;
	}
	else if (_suit == Card::SPADES) {
		numOfSpades--;
	}
	else {
		numOfDiamonds--;
	}
}

Deck::Deck(int numOfCards)
{
	deck = new queue<Card>();
	FillDeck(4,numOfCards);
}

void Deck::FillDeck(int numOfSuits,int numOfCards)
{
	for (int i = 0; i < numOfSuits; i++) {
		for (int j = 1; j < numOfCards + 1; j++) {
			temp.push_back(Card(j, Card::Suit(i)));
		}
	}
	for (int i = 0; i < numOfCards * numOfSuits; i++) {


		std::random_device rd;                 // Seed
		std::mt19937 gen(rd());                // Random number generator
		std::uniform_int_distribution<> dist(0, temp.size() - 1);
		int index = dist(gen);

		AddElement(temp[index]);
		temp.erase(temp.begin() + index);
	}
}

int Deck::GetDeckSize()
{
	return deck->size();
}

Card Deck::Test(int i)
{
	return temp[i];
}

bool Deck::DeckEmpty()
{
	return deck->empty();
}

queue<Card> Deck::ReturnDeck()
{
	return *deck;
}
