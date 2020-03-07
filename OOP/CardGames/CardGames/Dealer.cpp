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

void Dealer::DealerTurn(int aNumber, std::vector<Player*> players)
{
	int highest_value = 0;

#pragma region checks the highest value of all players
	for (int i = 0; i < players.size(); i++)
	{
		int value;
		value = players.at(i)->getHand()->getBalance();
		if (value > highest_value)
		{
			value = highest_value;
		}
	}
#pragma endregion

#pragma region dealerAI

	if (cardBalance >= 17)
	{
		std::cout << "Dealer: stand!" << std::endl;
	}
	else if (cardBalance > highest_value)
	{
		std::cout << "Dealer: stand!" << std::endl;
	}
	else if (cardBalance >= highest_value && cardBalance > 11)
	{
		std::cout << "Dealer: stand!" << std::endl;
	}
	else if (cardBalance >= highest_value && cardBalance < 12)
	{
		std::cout << "Dealer: hit!" << std::endl;
		deck.DrawCard(NULL,1,1, );
	}
	else
	{
		std::cout << "Dealer: hit!" << std::endl;
	}

#pragma endregion
	
}

void Dealer::setDeck(Deck aDeck)
{
	deck = aDeck;
}