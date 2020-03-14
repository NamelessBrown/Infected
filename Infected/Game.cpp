#include "Game.h"
#include <iostream>

Game::Game()
	:mRd(), Mmt(mRd()),
	mInfectedButton(sf::Vector2f(50.f, 150.f), "Infected", sf::Color::Red, sf::Vector2f(25.f,25.f), "Font/Nervous.ttf", 25)
{
	m_window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Infected", sf::Style::Close | sf::Style::Titlebar);
	m_event = new sf::Event();

	mFont.loadFromFile("Font/Nervous.ttf");
	mInfectedText.setFont(mFont);
	mInfectedText.setCharacterSize(12);
	mInfectedText.setPosition(0.f, 250.f);

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
					e.GotInfected((int)e.getDisease().mDiseaseType);
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
	std::stringstream ss;

	for (auto& e : mPeoples)
	{
		ss << e.getName() << " has gotten the " << e.getDisease().mDiseaseName << "!\n";
		mInfectedText.setString(ss.str());
	}


}

void Game::Render()
{

	m_window->clear();

	mInfectedButton.Draw(*m_window);

	m_window->draw(mInfectedText);

	m_window->display();
}
