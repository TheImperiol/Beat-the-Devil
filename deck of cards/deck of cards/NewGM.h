#pragma once
#include <iostream>
#include "Table.h"
#include <stack>
using namespace std;
class NewGM
{
public:
	void StartGame();
	void GameLoop();
	void CheckIfPileMatches(Card card, int index, bool secondAttempt, bool piles, int startingIndex);
	void CheckForPotentialMatches();
	void UpdatedCheckIfPileMatches(Card card, int index, bool piles);
private:
	CardTable table = CardTable();
};

