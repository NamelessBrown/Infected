// SFML_template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Game.h"
#include <iostream>

int main()
{
	Game game;

	constexpr int size = 10;

	std::vector<Human> people(50);

	for (int i = 0; i < people.size(); ++i)
	{
		people[i].GotInfected();
	}

	game.Run();
}

