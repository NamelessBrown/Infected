#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include "Human.h"
#include "Button.h"

class Game
{
public:
	Game();
	Game(const Game&) = delete;
	~Game();

	void Run();
private:
	//random numbers gen
	std::random_device mRd;
	std::mt19937 Mmt;

	//SFML 
	sf::RenderWindow* m_window;
	sf::Event* m_event;
	sf::Vector2i mMousePosition;
	sf::Font mFont;
	sf::Text mInfectedText;
	sf::Text mDeathText;
	sf::Text mKillCount;

	//Game related stuff
	Button mInfectedButton;
	Button mArmageddon;
	std::vector<Human> mPeoples;
	int mDeaths;
	bool mBeganArmageddon;

	//game functions
	void DiedByDisease();

	//private functions
	void PollEvent();
	void Update();
	void Render();
	
};

