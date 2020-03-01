#pragma once
#include "string"

class IO
{
public:
	IO();
	~IO();

	std::string AskString(std::string aString, int aNumber);
	bool AskBool(std::string aString);
	int AskInt(std::string aString, int aNumber);
};

