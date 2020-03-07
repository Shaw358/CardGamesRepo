#pragma once
#include <vector>
#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include "Dealer.h"

class Deck
{
public:
	Deck();
	~Deck();

	void DrawCard(Player* aPlayer, int anAmount, int aPlayerType, Dealer* dealer);

	void Fill();

	void Erase();

	void Shuffle();

	void ShowRemainingCards();

private:
	std::vector<Card*> remainingCards;
	int randomInt; 
	
};