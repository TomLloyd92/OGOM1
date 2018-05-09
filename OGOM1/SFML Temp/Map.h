#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

class Map
{
private:
	//Texture Sprites
	sf::Texture m_pavementText;
	sf::Texture m_roadText;
	sf::Sprite m_floorSprite;

	//Position
	int m_xPos = 0;
	int m_yPos = 0;

	//Tile Selector
	bool isRoadTile = false;

public:
	//Default Constructor
	Map();

	//Setup textures and Sprites
	void setup();
	void loadTextures();
	void setSprite();
	void setPosition(int t_xPos, int t_yPos);

	void setIsRoadTile(bool t_roadTile);

	sf::Sprite getSprite();
	bool getIsRoadTile();

	//Update
	void update();

};