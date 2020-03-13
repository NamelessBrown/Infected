#include "Human.h"
#include <iostream>

Human::Human()
	:mIsInfected(false), mRd(), mMt(mRd()), mAgeDistribution(0, 100), mNameDistribution(0, m_names.size() - 1)
{
	mAge = mAgeDistribution(mMt);

	mName = m_names.at(mNameDistribution(mMt));

}
