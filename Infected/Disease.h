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
	Disease() = default;
	Disease(const std::string diseaseName);
public:
	std::string mDiseaseName;
	DiseaseType mDisease;

private:
	std::random_device rd;
	std::mt19937 mt;
	std::uniform_int_distribution<int> distribution;

};
