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
#include "Dealer.h"
#include "CardType.h"

int main()
{
#pragma region Global Variables

	int currentPlayer = 0;
	Deck deck;
	IO io;
	Player* player;
	Dealer* dealer;
	std::string choiceString;
	int choiceInt;
	bool choiceBool;
	int game_speed;

	std::vector<Player*> players;
	std::vector<long long int> playerBets;
	dealer = new Dealer;

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
	//deck.ShowRemainingCards();

	choiceInt = io.AskInt("How many players will be participating?", 1);

	for (int i = 0; i < choiceInt; i++)
	{
		players.push_back(new Player());
	}

	//start cards
	for (int i = 0; i < players.size(); i++, currentPlayer++)
	{
		deck.DrawCard(players.at(currentPlayer), 2, 1, NULL);
	}

	currentPlayer = 0;
	choiceInt = 0;

#pragma endregion setup phase end

	currentPlayer = 0;
	for (int i = 0; i < players.size(); i++, currentPlayer++)
	{
		playerBets.push_back(io.AskInt("Dealer: player X player, place your bet.", 1));
	}

	currentPlayer = 0;

	for (int i = 0; i < players.size(); i++, currentPlayer++)
	{
		int currentCard = 0;

		for (int i = 0; i < players.at(currentPlayer)->getHand()->getCards()->size(); i++)
		{
			if (players.at(currentPlayer)->getHand()->getCards()->at(i)->getCardType() == CardType::CLUBS)
			{

				std::cout << "Card: " << players.at(currentPlayer)->getHand()->getCards()->at(currentCard)->GetValue() << " club" << std::endl;
				currentCard++;

			}
			else if (players.at(currentPlayer)->getHand()->getCards()->at(i)->getCardType() == CardType::HEARTS)
			{

				std::cout << "Card: " << players.at(currentPlayer)->getHand()->getCards()->at(currentCard)->GetValue() << " Heart" << std::endl;
				currentCard++;

			}
			else if (players.at(currentPlayer)->getHand()->getCards()->at(i)->getCardType() == CardType::SPADES)
			{

				std::cout << "Card: " << players.at(currentPlayer)->getHand()->getCards()->at(currentCard)->GetValue() << " Spade" << std::endl;
				currentCard++;

			}
			else if (players.at(currentPlayer)->getHand()->getCards()->at(i)->getCardType() == CardType::DIAMONDS)
			{

				std::cout << "Card: " << players.at(currentPlayer)->getHand()->getCards()->at(currentCard)->GetValue() << " diamond" << std::endl;
				currentCard++;

			}
		}



		std::cout << "Dealer: Player " << currentPlayer + 1 << " card value: " << players.at(0)->getHand()->getBalance() << std::endl;

		while (choiceInt != 1)
		{
			int currentCard = 0;

			choiceInt = io.AskInt("Dealer: hit or stand?", 0);
			switch (choiceInt)
			{
			case 0:
				deck.DrawCard(players.at(currentPlayer), 1, 1, NULL);
				if (players.at(currentPlayer)->getHand()->getBalance() > 21)
				{
					std::cout << "Dealer: player " << currentPlayer + 1 << " busted!" << std::endl;
					std::cout << "Dealer: Player " << currentPlayer + 1 << " cards value: " << players.at(currentPlayer)->getHand()->getBalance() << std::endl;
					//player busted!
				}

				for (int i = 0; i < players.at(currentPlayer)->getHand()->getCards()->size(); i++)
				{
					if (players.at(currentPlayer)->getHand()->getCards()->at(i)->getCardType() == CardType::CLUBS)
					{

						std::cout << "Card: " << players.at(currentPlayer)->getHand()->getCards()->at(currentCard)->GetValue() << " club" << std::endl;
						currentCard++;

					}
					else if (players.at(currentPlayer)->getHand()->getCards()->at(i)->getCardType() == CardType::HEARTS)
					{

						std::cout << "Card: " << players.at(currentPlayer)->getHand()->getCards()->at(currentCard)->GetValue() << " Heart" << std::endl;
						currentCard++;

					}
					else if (players.at(currentPlayer)->getHand()->getCards()->at(i)->getCardType() == CardType::SPADES)
					{

						std::cout << "Card: " << players.at(currentPlayer)->getHand()->getCards()->at(currentCard)->GetValue() << " Spade" << std::endl;
						currentCard++;

					}
					else if (players.at(currentPlayer)->getHand()->getCards()->at(i)->getCardType() == CardType::DIAMONDS)
					{

						std::cout << "Card: " << players.at(currentPlayer)->getHand()->getCards()->at(currentCard)->GetValue() << " diamond" << std::endl;
						currentCard++;

					}
				}

				std::cout << "Dealer: Player " << currentPlayer + 1 << " cards value: " << players.at(currentPlayer)->getHand()->getBalance() << std::endl;
				break;

			case 1:

				for (int i = 0; i < players.at(currentPlayer)->getHand()->getCards()->size(); i++)
				{
					if (players.at(currentPlayer)->getHand()->getCards()->at(i)->getCardType() == CardType::CLUBS)
					{

						std::cout << "Card: " << players.at(currentPlayer)->getHand()->getCards()->at(currentCard)->GetValue() << " club" << std::endl;
						currentCard++;

					}
					else if (players.at(currentPlayer)->getHand()->getCards()->at(i)->getCardType() == CardType::HEARTS)
					{

						std::cout << "Card: " << players.at(currentPlayer)->getHand()->getCards()->at(currentCard)->GetValue() << " Heart" << std::endl;
						currentCard++;

					}
					else if (players.at(currentPlayer)->getHand()->getCards()->at(i)->getCardType() == CardType::SPADES)
					{

						std::cout << "Card: " << players.at(currentPlayer)->getHand()->getCards()->at(currentCard)->GetValue() << " Spade" << std::endl;
						currentCard++;

					}
					else if (players.at(currentPlayer)->getHand()->getCards()->at(i)->getCardType() == CardType::DIAMONDS)
					{

						std::cout << "Card: " << players.at(currentPlayer)->getHand()->getCards()->at(currentCard)->GetValue() << " diamond" << std::endl;
						currentCard++;

					}
				}
				
				std::cout << "Dealer: Player " << currentPlayer + 1 << " cards value: " << players.at(currentPlayer)->getHand()->getBalance() << std::endl;
				break;

			case 100:
				std::cout << "Exiting game..." << std::endl;
				return 0;
			}
		}
	}

	int dealerResponse;
	for (int i = 0; i < players.size(); i++)
	{
		dealerResponse = dealer->DealerTurn(1, players.at(i));
		switch (dealerResponse)
		{
		case 0:
			std::cout << "Dealer: stand!" << std::endl;

			break;
		case 1:
			std::cout << "Dealer: hit!" << std::endl;
			deck.DrawCard(NULL, 1, 0, dealer);
			break;
		}

	}

	int dealerBalance = dealer->getBalance();

	for (int i = 0; i < players.size(); i++)
	{
		if (dealerBalance > players.at(i)->getHand()->getBalance())
		{
			std::cout << "Dealer: " << "player " << i << " lost!";
			playerBets.at(i) = 0;
		}
		else if (dealerBalance < players.at(i)->getHand()->getBalance())
		{
			std::cout << "Dealer: " << "player " << i << " won!";
			players.at(i)->setBalance(playerBets.at(i) * 2);
		}
		else if (dealerBalance == players.at(i)->getHand()->getBalance())
		{
			std::cout << "Dealer: " << "player " << i << " push!";
			playerBets.at(i) = 0;
		}
		else
		{
			std::cout << "Unrecognised action...";
		}
	}
}