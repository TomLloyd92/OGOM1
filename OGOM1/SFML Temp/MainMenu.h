#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

class MainMenu
{
private:
	sf::Font m_font;
	sf::Text m_messageGame;
	sf::Text m_messageHelp;

	sf::Texture m_menuTexture;
	sf::Sprite m_menuSprite;

	void setTexture();
	void setSprite();

	bool m_gameSelected;
	bool m_helpSelected;

public:
	MainMenu();
	void update(sf::Time t_deltaTime, sf::RenderWindow &t_window);
	void render(sf::RenderWindow &t_window);
	void setup(sf::Font &t_font);


};