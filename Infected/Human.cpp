#include "Human.h"
#include <iostream>

Human::Human(std::mt19937 mt)
	:mIsInfected(false), mAgeDistribution(0, 100), mNameDistribution(0, m_names.size() - 1), mIsDead(false), mHealth(0),
	mStatusDistribution(0, 6), mMoney(0), mDisease(mt)
{
	mAge = mAgeDistribution(mt);

	mName = m_names.at(mNameDistribution(mt));

	mStatus = static_cast<Status>(mStatusDistribution(mt));

	/* This will determine the persons wealth and health */
	switch (mStatus)
	{
	case Status::Homeless:
		mMoney = 0;
		mHealth = 10;
		break;
	case Status::Poor:
		mMoney = 15;
		mHealth = 25;
		break;
	case Status::LowClass:
		mMoney = 50;
		mHealth = 50;
		break;
	case Status::MiddleClass:
		mMoney = 100;
		mHealth = 75;
		break;
	case Status::HighClass:
		mMoney = 1000;
		mHealth = 100;
		break;
	case Status::TrumpClass:
		mMoney = 100000000;
		mHealth = 1000;
		break;
	}

}
/* Got infected to bad... If you have enough money you can go to a doctor and they will help you keep living! */
void Human::GotInfected(int timesByDiseaseType)
{
	mHealth -= mHealth * timesByDiseaseType;

	if (mHealth < 0 && mMoney > timesByDiseaseType * 25)
	{
		mHealth += timesByDiseaseType + 100;
	}

	UpdateDate();
}

/* No need to worry. I know that some month don't have 30, but most do and I don't feel like adding all of that! */
void Human::UpdateDate()
{
	mDate.mDay++;

	if (mDate.mDay > 30)
	{
		mDate.mDay = 1;
		mDate.mMonth++;
	}

	if (mDate.mMonth > 12)
	{
		mDate.mDay = 1;
		mDate.mMonth = 1;
		mDate.mYear++;
	}
}
