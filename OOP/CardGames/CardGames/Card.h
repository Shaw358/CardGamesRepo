#pragma once
#include "CardType.h"

class Card
{
public:
	Card(int aValue);
	~Card();

	void setValue(int aValue);

	int GetValue();

	void setCardType(int aValue);

	CardType getCardType();

private:
	CardType typeOfCard;
	
	int value;
};