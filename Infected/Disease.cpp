#include "Disease.h"

Disease::Disease(const std::string diseaseName)
	:rd(), mt(rd()), distribution(0, 7)
{
	mDisease = static_cast<DiseaseType>(distribution(mt));
}
