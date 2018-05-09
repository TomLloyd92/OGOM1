#include "Splash.h"
#include "Game.h"

Splash::Splash()
{
	loadtextures();
}

void Splash::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		Game::m_currentMode = GameMode::MainMenu;
	}
}

void Splash::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_splashSprite);
	t_window.display();
}

void Splash::setUp(sf::Font & t_font)
{
	m_splashSprite.setTexture(m_splashText);
}

void Splash::loadtextures()
{
	if (!m_splashText.loadFromFile("ASSETS\\IMAGES\\Splash.jpg"))
	{
		std::cout << "problem loading Splash texture" << std::endl;
	}
}
