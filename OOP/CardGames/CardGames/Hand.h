#pragma once
#include "Card.h"
#include <vector>
class Hand
{
public:
	Hand();
	~Hand();

	std::vector<Card*>* getCards();
	int getBalance();
	void setBalance();

private:
	std::vector<Card*>* cards = new std::vector<Card*>();
	int balance;
};
