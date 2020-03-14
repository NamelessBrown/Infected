#include "Game.h"
#include <iostream>

Game::Game()
	:mRd(), Mmt(mRd()),
	mInfectedButton(sf::Vector2f(250.f, 250.f), "Infected", sf::Color::Red, sf::Vector2f(25.f,25.f), "Font/Nervous.ttf", 25)
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
			mMousePosition = sf::Mouse::getPosition(*m_window);

			if (mInfectedButton.IsClicked(mMousePosition))
			{
				for (auto& e : mPeoples)
				{
					e.GotInfected();
				}

				Mmt.seed(mRd());
				mPeoples.push_back(Human(Mmt));

			}
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

	mInfectedButton.Draw(*m_window);

	m_window->display();
}
