#include "Game.h"

Game::Game()
	:mRd(), Mmt(mRd()), mDeaths(0), mBeganArmageddon(false),
	mInfectedButton(sf::Vector2f((float)sf::VideoMode::getDesktopMode().width / 2, (float)sf::VideoMode::getDesktopMode().height / 2), "Infected", sf::Color::Red, sf::Vector2f(25.f,25.f), "Font/Nervous.ttf", 25),
	mArmageddon(sf::Vector2f((float)sf::VideoMode::getDesktopMode().width / 2, 500), "Unleash_Armageddon!", sf::Color::Green, sf::Vector2f(25.f, 25.f), "Font/Nervous.ttf", 25),
	mMusicButton(sf::Vector2f((float)sf::VideoMode::getDesktopMode().width / 2, 700), "Music!", sf::Color::Blue, sf::Vector2f(25.f, 25.f), "Font/Nervous.ttf", 25)
{
	m_window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Infected", sf::Style::Close | sf::Style::Titlebar);
	m_event = new sf::Event();



	mFont.loadFromFile("Font/Nervous.ttf");
	mInfectedText.setFont(mFont);
	mInfectedText.setCharacterSize(15);
	mInfectedText.setPosition(0.0f, 350.f);

	mDeathText.setFont(mFont);
	mDeathText.setCharacterSize(15);
	mDeathText.setPosition(50.f, 5.0f);

	mKillCount.setFont(mFont);
	mKillCount.setCharacterSize(15);
	mKillCount.setPosition(1000, 250);
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

void Game::DiedByDisease()
{
	std::vector<Human>::iterator iter;
	std::stringstream deathStream;
	std::stringstream killCountStream;

	for (iter = mPeoples.begin(); iter != mPeoples.end();)
	{
		if (iter->getHealth() <= 0)
		{
			mDeaths++;
			deathStream << iter->getName() << " has died from " << iter->getDisease().mDiseaseName << '.' << ' ' << iter->getName() <<
				" has died on " << iter->getDate().mYear << '/' << iter->getDate().mMonth << '/' << iter->getDate().mDay << '.' << ' ' <<
				iter->getName() << " died at the age of " << iter->getAge() << '\n';

			mDeathText.setString(deathStream.str());

			iter = mPeoples.erase(iter);

			killCountStream << "Kill count: " << mDeaths << '\n';
			mKillCount.setString(killCountStream.str());

		}
		else
		{
			iter++;
		}
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

			if (mBeganArmageddon)
			{
				if (mArmageddon.IsClicked(mMousePosition))
				{
					for (auto& e : mPeoples)
					{
						e.GotInfected(1000000);
					}

					Mmt.seed(mRd());
					mPeoples.push_back(Human(Mmt));
				}
			}

			if (mMusicButton.IsClicked(mMousePosition))
			{
				mMusic.Play();
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
		ss << e.getName() << " has gotten the " << e.getDisease().mDiseaseName << "! " << e.getName() << " health is " << e.getHealth() << '\n';
		mInfectedText.setString(ss.str());
	}

	if (mDeaths > 100)
	{
		mBeganArmageddon = true;
	}

	DiedByDisease();
}

void Game::Render()
{

	m_window->clear();

	mInfectedButton.Draw(*m_window);

	if (mBeganArmageddon)
	{
		mArmageddon.Draw(*m_window);
	}

	mMusicButton.Draw(*m_window);

	m_window->draw(mInfectedText);
	m_window->draw(mDeathText);
	m_window->draw(mKillCount);

	m_window->display();
}
