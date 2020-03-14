#pragma once

#include "Disease.h"
#include <vector>

struct Date
{
	unsigned int mYear;
	unsigned int mMonth;
	unsigned int mDay;
public:
	Date()
	{
		mYear = 2020;
		mMonth = 3;
		mDay = 15;
	}
};

class Human
{
public:
	Human(std::mt19937 mt);

	void GotInfected(int timesByDiseaseType);

	//getters
	const std::string& getName() const { return mName; }
	const int& getAge() const { return mAge; }
	const Disease& getDisease() const { return mDisease; }
	const Date& getDate() { return mDate; }

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
	Date mDate;

	std::vector<std::string> m_names{
		"Joe", "Bob", "Frank", "Billy", "Adien", "NamelessBrown", "Mia", "Madison", "Chole", "Orion", "Marlon", "Chris", "Reggie",
		"CodePrime8", "TheFatRat", "Laura_Brehm", "Jonathon_Hills", "Mr.Butts", "Physical_Gamerz", "Mr.Miss", "Ariana", "Squidward",
		"Spongeboob", "Patrick", "Sandy", "Miss.Puff", "Wille", "Cameron", "Jesus", "Buddha", "Berleezy", "Infected_monsta", "Mr.Horrigan",
		"The_Lone_Wanderer", "Lily_Madwhip", "Kevin_Macleod", "ChiliTomatoNoodle", "The_toe_bro", "Varyana", "Hugo_One", "Don", "Mr.Smith",
		"Jameek", "Close_to_Me", "Bill Gates", "Richard_Burnish", "Steven", "Leory_Sinclair", "Lily", "Mr.Mad_Enclave_Man", "SHAUN!", "GLaDOS"
	};


	std::uniform_int_distribution<int> mAgeDistribution;
	std::uniform_int_distribution<int> mNameDistribution;
	std::uniform_int_distribution<int> mStatusDistribution;

	//functions
	void UpdateDate();
};

