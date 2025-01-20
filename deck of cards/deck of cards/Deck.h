#pragma once
#include "CardInterface.h"
#include <iostream>
#include <queue>
#include <random>
#include <list>

using namespace std;

class Deck
{
public:
	void AddElement(Card card);
	Card TakeCard();
	void DecreaseNumOfSuit(Card::Suit _suit);
	Deck(int numOfSuits);
	void FillDeck(int numOfCards, int numOfSuits);
	int GetDeckSize();
	Card Test(int i);
	bool DeckEmpty();
	queue<Card> ReturnDeck();
private:
	queue<Card>* deck;
	vector<Card> temp;
	int numOfClubs; 
	int numOfSpades; 
	int numOfHearts; 
	int numOfDiamonds;
};

