#include <iostream>
#include <string>
#include "vector"
#include <cctype>
#include <windows.h>
#include <ctime>
#include <cstdlib>
using namespace std;

#pragma region Variables

int gameMode;

std::vector<int> cards;
std::vector<int> playerCards;
std::vector<int> dealerCards;

enum Aces { ace0 = 1, ace1 = 1, ace2 = 1, ace3 = 1 };

std::string playerName;
int randomized = 0;

int credits = 2000;
int bettedCredits;

std::string playerInput;
int choice;

int PlayerCardValue = 0;
int DealerCardvalue = 0;

bool dealerDone;
bool dealerBusted;

#pragma endregion

void FillCardVector()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 2; j < 11; j++)
		{
			cards.push_back(j);
		}
	}

	cards.push_back(ace0);
	cards.push_back(ace1);
	cards.push_back(ace2);
	cards.push_back(ace3);

}

void PickGame()
{
	while (playerInput.empty())
	{
		system("CLS");
		std::cout << "Please pick a game" << endl;
		std::cout << "1: BlackJack \n2: Poker \n3: War" << endl;
		std::cin >> playerInput;
		choice = stoi(playerInput);
		if (choice == 1)
		{
			gameMode = choice;
		}
		else if (choice == 2)
		{
			gameMode = choice;
		}
		else if (gameMode == 3)
		{
			gameMode = choice;
		}

	}
}

void InstructionsBlackJack()
{
	system("CLS");
	std::cout << "Hello " << playerName << endl;
	cin.ignore();
	std::cout << "I am here to quickly explaint to you how blackjack works" << endl;
	std::cout << "Press enter to proceed" << endl;
	cin.ignore();
	std::cout << "You are playing to get a total card value of 21" << endl;
	cin.ignore();
	std::cout << "If you exceed this number, you lose" << endl;
	cin.ignore();
	std::cout << "Likewise the dealer also isn't allowed to go over 21" << endl;
	cin.ignore();
	std::cout << "If someone hits a 21 on their first draw he automatically wins, if both parties have 21 on their first draw the dealer wins" << endl;
	cin.ignore();
	std::cout << "If no parties reach 21 before standing, the party with the highest total score wins" << endl;
	cin.ignore();
	std::cout << "Good luck!" << endl;
	std::cout << "Press enter to proceed" << endl;
	cin.ignore();
	system("CLS");
}

void GetCard(unsigned short int player)
{
	srand(time(0));

	randomized = rand() % cards.size();

	switch (player)
	{
	case 0:
		std::move(cards.begin() + randomized - 1, cards.begin() + randomized, std::back_inserter(playerCards));

		/*if (std::find(playerCards.begin(), playerCards.end(), ace0) != playerCards.end())
		{

		}*/

		PlayerCardValue = 0;
		for (auto& i : playerCards)
			PlayerCardValue += i;
		break;
	case 1:
		std::move(cards.begin() + randomized - 1, cards.begin() + randomized, std::back_inserter(dealerCards));
		DealerCardvalue = 0;
		for (auto& i : dealerCards)
			DealerCardvalue += i;
		break;
	}
}

void endingScreens(int result)
{
	system("CLS");
	switch (result)
	{
	case 0:
		std::cout << "Your hand: " << PlayerCardValue << endl;
		std::cout << "Dealer hand: " << DealerCardvalue << endl;
		bettedCredits *= 2;
		std::cout << "You win!\nCredits earned: " << bettedCredits << endl;
		credits += bettedCredits;
		Sleep(3000);
		break;
	case 1:
		std::cout << "Your hand: " << PlayerCardValue << endl;
		std::cout << "You lost!" << endl;
		std::cout << "Credits lost: " << bettedCredits << endl;
		credits -= bettedCredits;
		Sleep(3000);
		break;
	case 2:
		std::cout << "Push!" << endl;
		std::cout << "Credits earned: 0 " << endl;
		credits += bettedCredits;
		Sleep(3000);
		break;
	case 5:
		std::cout << "BlackJack!";
		Sleep(2000);
		system("CLS");
		bettedCredits *= 2.5f;
		std::cout << "Credits earned: " << bettedCredits << endl;
		credits += bettedCredits;
		Sleep(3000);
		break;

	}
}

void DealerTurn()
{
	system("CLS");
	dealerBusted = false;
	for (int i = 0; i < 2; i++)
	{
		GetCard(1);
	}

	std::cout << "Your hand: " << PlayerCardValue << endl;
	std::cout << "Dealer hand: " << DealerCardvalue << endl;

	Sleep(2000);

	while (true)
	{
		system("CLS");

		if (DealerCardvalue == 17)
		{
			std::cout << "Dealer hand: " << DealerCardvalue << endl;
			std::cout << "Dealer stands!" << endl;
			dealerDone = true;
			Sleep(2000);
			break;
		}
		else if (DealerCardvalue > 21)
		{
			dealerBusted = true;
			dealerDone = true;
			std::cout << "Your hand: " << PlayerCardValue << endl;
			std::cout << "Dealer hand: " << DealerCardvalue << endl;
			std::cout << "Dealer busted!" << endl;
			Sleep(2000);
		}
		else if (DealerCardvalue > 17)
		{
			std::cout << "Your hand: " << PlayerCardValue << endl;
			std::cout << "Dealer hand: " << DealerCardvalue << endl;
			std::cout << "Dealer Stands!" << endl;
			Sleep(2000);
			dealerDone = true;
		}
		else if (DealerCardvalue < PlayerCardValue)
		{
			if (DealerCardvalue < 17 && PlayerCardValue > DealerCardvalue)
			{
				system("CLS");
				GetCard(1);
				std::cout << "dealer hits" << endl;
				Sleep(2000);
				std::cout << "Your hand: " << PlayerCardValue << endl;
				std::cout << "Dealer hand: " << DealerCardvalue << endl;
				Sleep(2000);
			}
			else
			{
				std::cout << "Dealer Stands!" << endl;
				Sleep(2000);
				std::cout << "Your hand: " << PlayerCardValue << endl;
				std::cout << "Dealer hand: " << DealerCardvalue << endl;
				Sleep(2000);
				dealerDone = true;
			}
		}
		else
		{
			std::cout << "Dealer Stands!" << endl;
			Sleep(2000);
			std::cout << "Your hand: " << PlayerCardValue << endl;
			std::cout << "Dealer hand: " << DealerCardvalue << endl;
			Sleep(2000);
			dealerDone = true;
		}

		system("CLS");
		std::cout << "Your hand: " << PlayerCardValue << endl;
		std::cout << "Dealer hand: " << DealerCardvalue << endl;
		Sleep(2000);
		if (dealerDone == true)
		{
			break;
		}
	}

	if (PlayerCardValue > DealerCardvalue || dealerBusted == true)
	{
		endingScreens(0);
	}
	else if (PlayerCardValue < DealerCardvalue && dealerBusted == false)
	{
		endingScreens(1);
	}
	else if (PlayerCardValue == DealerCardvalue)
	{
		endingScreens(2);
	}
}


int main()
{
	FillCardVector();
	PickGame();

	while (playerName.empty())
	{
		std::cout << "Please enter your name" << endl;
		std::cin >> playerName;
	}

	switch (gameMode)
	{
	case 1:
		InstructionsBlackJack();

		while (true)
		{
			dealerDone = false;
			system("CLS");
			std::cout << "New Round!";

			PlayerCardValue = 0;
			DealerCardvalue = 0;

			playerCards.clear();
			dealerCards.clear();

			Sleep(2000);

			while (true)
			{
				system("CLS");
				std::cout << "Credits in account: " << credits << endl;
				std::cout << "How much credits do wish to bet?" << endl;
				std::cin >> playerInput;
				bettedCredits = std::stoi(playerInput);
				if (bettedCredits <= credits && bettedCredits > 0)
				{
					system("CLS");
					std::cout << bettedCredits << " in the game" << endl;
					Sleep(2000);
					break;
				}
				else
				{
					std::cout << "Not enough credits!" << endl;
					Sleep(2000);
				}
			}

			for (int i = 0; i < 2; i++)
			{
				GetCard(0);
			}

			if (PlayerCardValue == 21)
			{
				endingScreens(5);
			}
			else
			{
				while (true)
				{
					system("CLS");
					std::cout << "Your hand: " << PlayerCardValue << endl;
					std::cout << "1: Draw an extra card \n2: Hold" << endl;

					std::cin >> playerInput;
					choice = stoi(playerInput);

					if (choice == 1)
					{
						GetCard(0);
						if (PlayerCardValue > 21)
						{
							endingScreens(1);
							break;
						}
					}
					else if (choice == 2)
					{
						std::cout << "Stand!" << endl;
						Sleep(200);
						std::cout << "Dealer turn" << endl;
						Sleep(2000);
						DealerTurn();
						break;
					}
				}
			}
		}
		break;
	case 2:
		break;
	case 3:
		break;
	}

	


}

#pragma region Later Use
/*



*/
#pragma endregion
