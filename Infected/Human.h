#pragma once

#include "Disease.h"
#include <vector>

class Human
{
public:
	Human();
private:
	int mAge;
	std::string mName;
	bool mIsInfected;
	Disease mDisease;

	std::vector<std::string> m_names{
		"Joe", "Bob", "Frank", "Billy", "Adien", "NamelessBrown", "Mia", "Madison", "Chole", "Orion", "Marlon", "Chris", "Reggie",
		"CodePrime8", "TheFatRat", "Laura_Brehm", "Jonathon_Hills", "Mr.Butts", "Physical_Gamerz", "Mr.Miss", "Ariana", "Squidward",
		"Spongeboob", "Patrick", "Sandy", "Miss.Puff", "Wille", "Cameron", "Jesus", "Buddha", "Berleezy", "Infected_monsta", "Mr.Horrigan",
		"The_Lone_Wanderer", "Lily_Madwhip", "Kevin_Macleod", "ChiliTomatoNoodle", "The_toe_bro", "Varyana", "Hugo_One", "Don", "Mr.Smith"
	};

	std::random_device mRd;
	std::mt19937 mMt;
	std::uniform_int_distribution<int> mAgeDistribution;
	std::uniform_int_distribution<int> mNameDistribution;

};

