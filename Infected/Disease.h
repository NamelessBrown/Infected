#pragma once

#include <string>
#include <random>

enum class DiseaseType
{
	Coronavirus = 0, Flu, BubonicPlague, HIV, Ebola, Smallpox, Influenza, Rabies
};

class Disease
{
public:
	Disease(std::mt19937 mt);
public:
	std::string mDiseaseName;
	DiseaseType mDiseaseType;

private: //No need for anybody to use this 
	std::uniform_int_distribution<int> distribution;
};
