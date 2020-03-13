#include "Disease.h"

Disease::Disease()
	:rd(), mt(rd()), distribution(0, 7)
{
	mDisease = static_cast<DiseaseType>(distribution(mt));

	//Names the disease ddepents on the type.
	switch (mDisease)
	{
	case DiseaseType::Coronavirus:
		mDiseaseName = "Coronavirus";
		break;
	case DiseaseType::Flu:
		mDiseaseName = "Flu";
		break;
	case DiseaseType::BubonicPlague:
		mDiseaseName = "Bubonic_Plague";
		break;
	case DiseaseType::HIV:
		mDiseaseName = "HIV";
		break;
	case DiseaseType::Ebola:
		mDiseaseName = "Ebola";
		break;
	case DiseaseType::Smallpox:
		mDiseaseName = "Smallpox";
		break;
	case DiseaseType::Influenza:
		mDiseaseName = "Influenza";
		break;
	case DiseaseType::Rabies:
		mDiseaseName = "Rabies";
		break;
	default:
		throw("OUT OF RANGE OF DISEASES!");
		break;
	}

}
