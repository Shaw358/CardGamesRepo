#include <iostream>
#include <string>
#include "vector"
#include <cctype>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <string.h>

#include "Deck.h"
#include "Player.h"
#include "IO.h"

int main()
{
#pragma region Global Variables

	int currentPlayer = 0;
	Deck deck;
	IO io;
	Player* player;
	int choiceInt;
	std::string choiceString;
	int choiceInt;
	bool choiceBool;

	std::vector<Player*> players;

#pragma endregion

#pragma region Setup Phase

	/*
	List of Functions:

	Fill > fills the entire deck with Card classes and assigns values to them.

	Shuffle > Randomizes the remainingCards vector from the Deck.

	ShowRemainingCards > Prints all the cards left in the remainingCards vector from the Deck.
	
	DrawCard > Gets the first Card class in the vector remainingCards in the Deck and puts in the [X player] hand.

	getHand > Gets the hand class from [X player].

	getbalance > Gets the balance from [X player].

	setBalance > Sets the [X player credits].

	askInt > Insert a question in the parameter and ask [X player] for a number.

	askBool > Insert a question in the parameter and ask [X player] for a bool.

	askString > Insert a question in the parameter and ask [X player] for a string. [Allows for commands!]
	*/

	deck.Fill();
	deck.Shuffle();
	deck.ShowRemainingCards();

	choiceInt = io.AskInt("How many players will be participating?", 2);

	for (int i = 0; i < choiceInt + 1; i++)
	{
		players.push_back(new Player());
	}
	
#pragma endregion setup phase end
	while (true)
	{
		for (int i = 0; i < players.size(); i++) 
		{
			deck.DrawCard(players.at(currentPlayer), 2);

			std::cout << "Dealer: Player " << currentPlayer << " card value: " << players.at(currentPlayer)->getHand()->getBalance() << std::endl;

			choiceInt = io.AskInt("Dealer: draw or stand?", 1);
		}
	}
}