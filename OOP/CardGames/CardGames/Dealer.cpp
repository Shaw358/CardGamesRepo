#include <iostream>
#include "Dealer.h"

Dealer::Dealer()
	:cardBalance(0)
{
}

Dealer::~Dealer()
{
}

int Dealer::getBalance()
{
	return cardBalance;
}

int Dealer::DealerTurn(int aNumber, Player* player)
{
	int highest_value = 0;

#pragma region checks the highest value of all players
	/*for (int i = 0; i < players.size(); i++)
	{
		int value;
		value = players.at(i)->getHand()->getBalance();
		if (value > highest_value)
		{
			value = highest_value;
		}
	}*/
#pragma endregion

#pragma region dealerAI

	if (cardBalance >= 17)
	{
		return 0;
	}
	else if (cardBalance > highest_value)
	{
		return 0;
	}
	else if (cardBalance >= highest_value && cardBalance > 11)
	{
		return 0;
	}
	else if (cardBalance >= highest_value && cardBalance < 12)
	{
		return 1;
	}
	else
	{
		return 1;
	}

#pragma endregion
	
}

void Dealer::getPlayerBalance()
{



}

std::vector<Card*>* Dealer::getCard()
{

	return cards;

}
