#include "NewGM.h"

void NewGM::StartGame()
{
	cout << "start game" << endl;
	
	table.CreateNewPile(table.GetDeck().TakeCard());
	cout << "cards in play pile: " << table.GetCardsInPlay()[0].top().value() << " " << table.GetCardsInPlay()[0].top().suit() << endl;
	cout << "size: " << table.GetCardsInPlay().size() << endl;
	GameLoop();
}

void NewGM::GameLoop()
{
	cout << "cards in play pile loop: " << table.GetCardsInPlay()[0].top().value() << " " << table.GetCardsInPlay()[0].top().suit() << endl;
	for (int i = 0; i < 8; i++) {
		cout << "loop: " << i << endl;
		Card drawnCard = table.GetDeck().TakeCard();
		cout << "size: " << table.GetCardsInPlay().size() << endl;
		cout << "drawn card stats: " << drawnCard.value() << " " << drawnCard.suit() << endl;
		cout << "cards in play pile: " << table.GetCardsInPlay()[0].top().value() << " " << table.GetCardsInPlay()[0].top().suit() << endl;

		CheckIfPileMatches(drawnCard, table.GetCardsInPlay().size() - 1, false, false, table.GetCardsInPlay().size() - 1);
		cout << "size: " << table.GetCardsInPlay().size() << endl;

		
		cout << "cards in play pile: " << table.GetCardsInPlay()[table.GetCardsInPlay().size() - 1].top().value() << " " << table.GetCardsInPlay()[table.GetCardsInPlay().size() - 1].top().suit() << endl;

		CheckForPotentialMatches();
	}
	cout << "num of piles: " << table.GetCardsInPlay().size() << endl;
}

void NewGM::CheckIfPileMatches(Card card, int index, bool secondAttempt, bool piles, int startingIndex)
{
	cout << "index: " << index << endl;
	cout << "starting index: " << startingIndex << endl;
	cout << "piles bool: " << piles << endl;
	if (index >= 0) {
		if (table.CheckCardCompatibilty(card, index)) {
			if (!piles) {
				cout << "compatible" << endl;
				table.AddCardToPile(card, index);
				CheckIfPileMatches(table.GetCardsInPlay()[index].top(), index - 1, false, true, startingIndex);
			}
			else {
				if (index != startingIndex) {

					table.CombinePiles(card, index, startingIndex);
					CheckIfPileMatches(table.GetCardsInPlay()[index].top(), index - 1, false, piles, startingIndex - 1);
					startingIndex = index;
				}
			}
		}
		else {
			cout << "not compatible" << endl; 
			if (!secondAttempt) {
				cout << "check next pile" << endl;
				CheckIfPileMatches(card, index - 1, true, piles, startingIndex);
			}
			else {
				cout << "no matches" << endl;
				
				table.CreateNewPile(card);
			}
		}
	}
	else {
		if (!piles) {
			if (secondAttempt) {
				cout << "creating new pile" << endl;
				table.CreateNewPile(card);
			}
		}
	}
	
}



void NewGM::CheckForPotentialMatches()
{
	cout << "checking potential matches" << endl;
	int numOfPiles = table.GetCardsInPlay().size() - 1;
	for (int i = numOfPiles; i >= 0; i--) {
		cout << "checking next" << endl;
		CheckIfPileMatches(table.GetCardsInPlay()[i].top(), i, false, true, i);
	}
	cout << "size after loop check: " << table.GetCardsInPlay().size() << endl;
}

void NewGM::UpdatedCheckIfPileMatches(Card card, int index)
{
	bool firstPileMatch = (index >= 0) ? table.CheckCardCompatibilty(card, index) : false; 
	bool secondPileMatch = (index - 1 >= 0) ? table.CheckCardCompatibilty(card, index - 1) : false;
	if (firstPileMatch && !secondPileMatch) {

	}
	else if (!firstPileMatch && secondPileMatch) {

	}
	else if (firstPileMatch && secondPileMatch) {

	}
	else {

	}
}
