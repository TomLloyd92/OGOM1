#include "Map.h"

Map::Map()
{
	setup();
}

void Map::setup()
{
	loadTextures();
	setSprite();
}

void Map::loadTextures()
{
	if (!m_pavementText.loadFromFile("ASSETS/IMAGES/pavement.jpg"))
	{
		std::cout << "Load Failed Pavement Square!" << std::endl;
	}

	if (!m_roadText.loadFromFile("ASSETS/IMAGES/road.jpg"))
	{
		std::cout << "Load Failed Road Square!" << std::endl;
	}

}

void Map::setSprite()
{
	if (isRoadTile == false)
	{
		m_floorSprite.setTexture(m_pavementText);
	}
	else if (isRoadTile == true)
	{
		m_floorSprite.setTexture(m_roadText);
	}
}

void Map::setPosition(int t_xPos, int t_yPos)
{
	m_xPos = t_xPos * 60;
	m_yPos = t_yPos * 60;
}

void Map::setIsRoadTile(bool t_roadTile)
{
	isRoadTile = t_roadTile;
}

sf::Sprite Map::getSprite()
{
	return sf::Sprite(m_floorSprite);
}

bool Map::getIsRoadTile()
{
	return isRoadTile;
}

void Map::update()
{
	m_floorSprite.setPosition(m_xPos, m_yPos);

	setSprite();
}
