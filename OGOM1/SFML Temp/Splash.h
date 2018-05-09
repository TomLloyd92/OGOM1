#pragma once

#include <SFML\Graphics.hpp>


class Splash
{
private:
	sf::Texture m_splashText;
	sf::Sprite m_splashSprite;

public:
	Splash();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow &t_window);
	void setUp(sf::Font &t_font);
	void loadtextures();
};