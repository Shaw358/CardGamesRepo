#pragma once
#include "Card.h"
#include <vector>
class Hand
{
public:
	Hand();
	~Hand();

	std::vector<Card*>* getCards();
	void setCard(Card* aCard);
	int getBalance();
	void setBalance(int aValue);

private:
	std::vector<Card*> cards;
	int balance;
};

