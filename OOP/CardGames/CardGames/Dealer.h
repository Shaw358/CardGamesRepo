#pragma once
#include <vector>
#include "Player.h"

class Dealer
{

public:
	Dealer();
	~Dealer();
	int getBalance();
	int DealerTurn(int aNumber, Player*);
	void getPlayerBalance();
	std::vector<Card*>* getCard();

private:
	int cardBalance;

	std::vector<Card*>* cards = new std::vector<Card*>();
};
