#pragma once
#include <iostream>
#include "Deck.h"
#include <stack>
using namespace std;
class CardTable
{
public:
	void AddPile(stack<Card> pileToAdd);
	void RemovePile(int index);
	void CombinePiles(Card card, int index, int startingIndex);
	bool CheckCardCompatibilty(Card drawnCard, int firstPile);
	void AddCardToPile(Card cardToPlace, int indexOfPile);
	void CreateNewPile(Card cardToAdd);
	bool CheckPileCompatibilty(int firstPile, int secondPile);
	vector<stack<Card>> GetCardsInPlay();
	Deck GetDeck();
private:
	vector<stack<Card>>* cardsInPlay = new vector<stack<Card>>();
	Deck deckOnTable = Deck(13);
};

