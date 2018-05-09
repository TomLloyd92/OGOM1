#include "MainMenu.h"
#include "Game.h"


MainMenu::MainMenu()
{
}

void MainMenu::setTexture()
{

	if (!m_menuTexture.loadFromFile("ASSETS\\IMAGES\\Menu.png"))
	{
		std::cout << "problem loading Menu" << std::endl;
	}
}

void MainMenu::setSprite()
{
	m_menuSprite.setTexture(m_menuTexture);
}
void MainMenu::update(sf::Time t_deltaTime, sf::RenderWindow & t_window)
{
}

void MainMenu::render(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Black);
	t_window.draw(m_menuSprite);
	t_window.display();
}

void MainMenu::setup(sf::Font & t_font)
{
	setTexture();
	setSprite();
}
