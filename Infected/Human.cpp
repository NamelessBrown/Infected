#include "Human.h"
#include <iostream>

Human::Human()
	:mIsInfected(false), mRd(), mMt(mRd()), mAgeDistribution(0, 100), mNameDistribution(0, m_names.size() - 1), mIsDead(false), mHealth(0),
	mStatusDistribution(0, 6), mMoney(0)
{
	mAge = mAgeDistribution(mMt);

	mName = m_names.at(mNameDistribution(mMt));

	mStatus = static_cast<Status>(mStatusDistribution(mMt));

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

void Human::GotInfected()
{
	if (mStatus != Status::TrumpClass)
	{
		std::cout << mName << " has been infected by the " << mDisease.mDiseaseName << "! \n";
	}
}
