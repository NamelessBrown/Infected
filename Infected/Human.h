#pragma once

#include "Disease.h"
#include <vector>

class Human
{
public:
	Human(std::mt19937 mt);

	void GotInfected();

private:

	enum class Status
	{
		Homeless = 0, Poor, LowClass, MiddleClass, HighClass, TrumpClass
	};

private:
	int mAge;
	int mHealth;
	int mMoney;
	bool mIsInfected;
	bool mIsDead;

	std::string mName;

	Status mStatus;
	Disease mDisease;

	std::vector<std::string> m_names{
		"Joe", "Bob", "Frank", "Billy", "Adien", "NamelessBrown", "Mia", "Madison", "Chole", "Orion", "Marlon", "Chris", "Reggie",
		"CodePrime8", "TheFatRat", "Laura_Brehm", "Jonathon_Hills", "Mr.Butts", "Physical_Gamerz", "Mr.Miss", "Ariana", "Squidward",
		"Spongeboob", "Patrick", "Sandy", "Miss.Puff", "Wille", "Cameron", "Jesus", "Buddha", "Berleezy", "Infected_monsta", "Mr.Horrigan",
		"The_Lone_Wanderer", "Lily_Madwhip", "Kevin_Macleod", "ChiliTomatoNoodle", "The_toe_bro", "Varyana", "Hugo_One", "Don", "Mr.Smith"
	};


	std::uniform_int_distribution<int> mAgeDistribution;
	std::uniform_int_distribution<int> mNameDistribution;
	std::uniform_int_distribution<int> mStatusDistribution;

};

