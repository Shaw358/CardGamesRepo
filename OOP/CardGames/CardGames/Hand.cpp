#include "Hand.h"

Hand::Hand()
	:balance(0)
{
}

Hand::~Hand()
{
}

std::vector<Card*>* Hand::getCards()
{
	return cards;
}

int Hand::getBalance()
{
	return totalBalance;
}

void Hand::setBalance(int aValue)
{
	int totalBalance = 0;
	for (int i = 0; i < cards.size(); i++)
	{
		totalBalance += cards.at(i)->GetValue();
	}
	totalBalance = balance;
}