#include "Table.h"

void CardTable::AddPile(stack<Card> pileToAdd)
{
	cardsInPlay->insert(cardsInPlay->end(), pileToAdd);
}

void CardTable::RemovePile(int index)
{
	cardsInPlay->erase(cardsInPlay->begin() + index);
}

void CardTable::CombinePiles(Card card, int index, int startingIndex)
{
	cout << "combining piles starting index: " << startingIndex << endl;
	cout << "size: " << cardsInPlay->size() << endl;
	//cout << "trying to erase: " << (cardsInPlay->begin() + startingIndex)->top().value() << endl;
	//cout << "first value : " << (cardsInPlay->begin())->top().value() << endl;
	AddCardToPile(card, index);
	cout << "added to pile for combination" << endl;
	cardsInPlay->erase(cardsInPlay->begin() + startingIndex);
}



bool CardTable::CheckCardCompatibilty(Card drawnCard, int pileToCheckAgainst)
{
	
	if (drawnCard.value() == (*cardsInPlay)[pileToCheckAgainst].top().value()
		|| drawnCard.suit() == (*cardsInPlay)[pileToCheckAgainst].top().suit()) {
		cout << "valid" << endl;
		cout << drawnCard.value() << endl; 
		cout << drawnCard.suit() << endl;
		cout << (*cardsInPlay)[pileToCheckAgainst].top().value() << endl;
		cout << (*cardsInPlay)[pileToCheckAgainst].top().suit() << endl;
		return true;
	}
	else {
		cout << "not valid" << endl;
		return false;
	}
	
}

void CardTable::AddCardToPile(Card cardToPlace, int indexOfPile)
{
	cout << "pile being added to: " << indexOfPile << endl;
	cout << "values of pile: " << (*cardsInPlay)[indexOfPile].top().value() << " " << (*cardsInPlay)[indexOfPile].top().suit() << endl;
	(*cardsInPlay)[indexOfPile].push(cardToPlace);
}

void CardTable::CreateNewPile(Card cardToAdd)
{
	stack<Card> temp; 
	temp.push(cardToAdd);
	cardsInPlay->insert(cardsInPlay->end(), temp);
}

bool CardTable::CheckPileCompatibilty(int firstPile, int secondPile)
{
	if ((*cardsInPlay)[firstPile].top().value() == (*cardsInPlay)[secondPile].top().value()
		|| (*cardsInPlay)[firstPile].top().suit() == (*cardsInPlay)[secondPile].top().suit()) {
		
		return true;
	}
	else {
		return false;
	}
}

vector<stack<Card>> CardTable::GetCardsInPlay()
{
	return *cardsInPlay;
}

Deck CardTable::GetDeck()
{
	return deckOnTable;
}


