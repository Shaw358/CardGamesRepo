#pragma once
#include <vector>
#include "Player.h"
#include "Deck.h"

class Dealer
{

public:
	Dealer();
	~Dealer();
	int getBalance();
	void DealerTurn(int aNumber, std::vector<Player*>);
	void setDeck(Deck aDeck);

private:
	int cardBalance;
	Deck deck;

	std::vector<Card*>* cards = new std::vector<Card*>();
};

