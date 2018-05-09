// author Tom Lloyd
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Map.h"
#include "globals.h"
#include "Splash.h"
#include "MainMenu.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

	//GameMode
	static GameMode m_currentMode;

private:
	//Set Up Assets
	void setUpAssets();

	//Game Loop
	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	
	//Text
	void setupFontAndText();
	void setupSprite();

	//Visual
	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo

	//Inputs
	bool m_exitGame; // control exiting game

	//Objects
	Map gameMap[MAX_TILES][MAX_TILES];

	Splash m_splashScreen;
	MainMenu m_mainMenuScreen;

	

};

#endif // !GAME

