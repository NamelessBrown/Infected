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

	//Game related stuff
	Button mInfectedButton;
	std::vector<Human> mPeoples;
	
	//game functions
	void DiedByDisease();

	//private functions
	void PollEvent();
	void Update();
	void Render();
	
};

