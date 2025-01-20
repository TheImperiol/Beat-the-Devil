#pragma once
#include "Table.h"
#include <iostream>
using namespace std;
class GameModeBeatDevil
{
public:
	GameModeBeatDevil(CardTable table);
	bool GameLoop();
	bool StartOfGame();
	void CardChecks(Card heldCard, bool piles, int inPlayIndex);
	void CardCheckHub();
private:
	CardTable _table;
};

