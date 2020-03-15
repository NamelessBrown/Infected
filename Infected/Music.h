#pragma once

#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <random>

class Music
{
public:
	Music();

	void Play();

private:
	sf::Music mMusic;
	std::vector<std::string> mSongs{ 10 };

	std::random_device mRd;
	std::mt19937 mMt;
	std::uniform_int_distribution<int> distribution;

	int mWhatFile;
};

