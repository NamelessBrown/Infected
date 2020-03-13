#include "Game.h"

Game::Game()
{
	m_window = new sf::RenderWindow(sf::VideoMode(500, 500, 32), "Infected", sf::Style::Close | sf::Style::Titlebar);
	m_event = new sf::Event();

}

Game::~Game()
{
	delete m_event;
	delete m_window;
}

void Game::Run()
{
	while (m_window->isOpen())
	{
		Update();
		Render();
	}
}

void Game::PollEvent()
{
	while (m_window->pollEvent(*m_event))
	{
		switch (m_event->type)
		{
		case sf::Event::Closed:
			m_window->close();
		case sf::Event::MouseButtonPressed:
			break;
		}
	}
}

void Game::Update()
{
	PollEvent();
}

void Game::Render()
{

	m_window->clear();

	

	m_window->display();
}
