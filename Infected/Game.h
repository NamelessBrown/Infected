#pragma once

#include <SFML/Graphics.hpp>
#include "Human.h"

class Game
{
public:
	Game();
	Game(const Game&) = delete;
	~Game();

	void Run();
private:
	sf::RenderWindow* m_window;
	sf::Event* m_event;

	void PollEvent();
	void Update();
	void Render();

};

