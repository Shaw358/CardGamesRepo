#include "Deck.h"
#include "string"
#include <iostream>
#include <vector>
#include <ctime>       
#include <cstdlib>    
#include <algorithm> 

Deck::Deck()
	:randomInt(0)
{
}

Deck::~Deck()
{
}

void Deck::DrawCard(Player* aPlayer = NULL, int anAmount = 1, int aPlayerType = 1, Dealer* dealer = NULL)
{
	if (remainingCards.size() > anAmount)
	{
		switch (aPlayerType)
		{
		case 0:
			//dealer draws card
			
			std::move(remainingCards.begin(), remainingCards.begin() + anAmount, std::back_inserter(*dealer->getCard()));

			break;
		case 1:
			//player draws card

			std::move(remainingCards.begin(), remainingCards.begin() + anAmount, std::back_inserter(*aPlayer->getHand()->getCards()));
			aPlayer->getHand()->setBalance();

			remainingCards.erase(remainingCards.begin(), remainingCards.begin() + anAmount);

			break;
		}
	}
}

void Deck::Fill()
{
	for (short unsigned int j = 0; j < 4; j++)
	{
		for (int i = 1; i < 11; i++)
		{
			Card* card = new Card(i);
			card->setCardType(j);
			remainingCards.push_back(card);
			remainingCards.back()->setCardType(1);
		}
	}
}

void Deck::Erase()
{



}

void Deck::Shuffle()
{
	srand(time(0));
	randomInt = rand() % remainingCards.size();
	std::random_shuffle(remainingCards.begin(), remainingCards.end());
}

void Deck::ShowRemainingCards()
{
	for (auto v : remainingCards)
	{
		std::cout << v->GetValue() << "\n";
	}
}


#pragma region garbage
/* for (int i = 0; i < anAmount; i++)
{
	aPlayer->getHand()->getCards()->push_back(std::move(remainingCards.back()));
	//remainingCards.erase(remainingCards.end, remainingCards.end);
}
*/


//std::move(remainingCards.begin(),remainingCards.begin() + anAmount, std::back_inserter(*aPlayer->getHand()->getCards()));
#pragma endregion
