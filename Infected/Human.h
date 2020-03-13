#pragma once

#include "Disease.h"

class Human
{
public:
	Human();
private:
	int mAge;
	std::string mName;
	bool mIsInfected;
	Disease mDisease;
};

