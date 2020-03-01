#include "IO.h"
#include "iostream"

IO::IO()
{
}

IO::~IO()
{
}

std::string IO::AskString(std::string aString, int aNumber)
{
	std::cout << aString << std::endl;
	std::string input;


	return input;
}

bool IO::AskBool(std::string aString)
{
	bool input;
	std::cout << aString << std::endl;
	std::cin >> input;
	return input;
}

int IO::AskInt(std::string aString, int aNumber)
{
	std::string input;
	int choiceInt;
	std::cout << aString << std::endl;

	while (true)
	{
		std::cin >> input;

#pragma region commands
		if (input.at(0) == '/')
		{
			if (input.find("add_credits") != std::string::npos)
			{
				//addTHemCREDITS
				std::cout << choiceInt << " credits added!";
			}
			else if (input.find("exit_game") != std::string::npos)
			{
				std::cout << "Exiting game...";
			}
		}
#pragma endregion
		else
		{
			switch (aNumber)
			{
			case 0:
				while (input != "hit" || "stand")
				{
					if (input == "hit")
					{
						return 0;
					}
					else if (input == "stand")
					{
						return 1;
					}
					else
					{
						std::cout << "Not a possible reply" << std::endl;
					}
				}
				break;
			case 1:



				break;
			case 2:
				//for selecting the amount of players
				choiceInt = std::stoi(input);
				return choiceInt;
				break;
			}
			
		}
	}
}
