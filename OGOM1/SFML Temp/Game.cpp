// author Tom Lloyd

#include "Game.h"
#include <iostream>

GameMode Game::m_currentMode{ GameMode::Splash };	//Initial GameMode

Game::Game() :
	m_window{ sf::VideoMode{ 360, 360, 32 }, "SFML Game" },
	m_exitGame{false}
{
	setUpAssets();
}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); 
			update(timePerFrame); 
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if ( sf::Event::Closed == event.type) 
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type)
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}
	}
}

void Game::update(sf::Time t_deltaTime)
{
	switch (m_currentMode)
	{
	case GameMode::Splash:
		m_splashScreen.update(t_deltaTime);
		break;
	case GameMode::MainMenu:
		m_mainMenuScreen.update(t_deltaTime, m_window);
	}


	//Exit Game
	if (m_exitGame)
	{
		m_window.close();
	}


	/*
	//Initial Set Up of Map
	for (int row = 0; row < MAX_TILES; row++)
	{
		for (int col = 0; col < MAX_TILES; col++)
		{
			gameMap[row][col].setIsRoadTile(false);
			gameMap[row][col].update();
			gameMap[row][col].setPosition(col, row);
		}
	}
	*/
}

void Game::render()
{
	//m_window.clear(sf::Color::White);

	switch (m_currentMode)
	{
	case GameMode::Splash:
		m_splashScreen.render(m_window);
		break;
	case GameMode::MainMenu:
		m_mainMenuScreen.render(m_window);
	}

	//Draw Map
	/*
	for (int row = 0; row < MAX_TILES; row++)
	{
		for (int col = 0; col < MAX_TILES; col++)
		{
			m_window.draw(gameMap[row][col].getSprite());
		}
	}
	*/

	//m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	/*
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_welcomeMessage.setFont(m_ArialBlackfont);
	m_welcomeMessage.setString("SFML Game");
	m_welcomeMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	m_welcomeMessage.setPosition(40.0f, 40.0f);
	m_welcomeMessage.setCharacterSize(80);
	m_welcomeMessage.setOutlineColor(sf::Color::Red);
	m_welcomeMessage.setFillColor(sf::Color::Black);
	m_welcomeMessage.setOutlineThickness(3.0f);
	*/
}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	
}

void Game::setUpAssets()
{
	m_splashScreen.setUp(m_ArialBlackfont);
	m_mainMenuScreen.setup(m_ArialBlackfont);
}
