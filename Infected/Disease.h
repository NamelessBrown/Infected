#pragma once

#include <string>
#include <random>

enum class DiseaseType
{
	Coronavirus = 0, Flu, BubonicPlague, HIV, Ebola, Smallpox, Influenza, Rabies
};

struct Disease
{
public:
	Disease();
public:
	std::string mDiseaseName;
	DiseaseType mDiseaseType;

private: //No need for anybody to use this 
	std::random_device rd;
	std::mt19937 mt;
	std::uniform_int_distribution<int> distribution;

};
