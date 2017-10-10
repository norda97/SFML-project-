#ifndef GAME_H
#define GAME_H

#include"TextureHandler.h"
#include"GameState.h"
#include"MenuState.h"
#include"StateHandler.h"

#include <SFML/Graphics.hpp>

#define WINDOW_SIZE 640, 480

class Game
{
public:
	Game();
	~Game();

	void init();
	void render(sf::RenderWindow & window);
	void input(const sf::Event & inputEvent);

private:
	sf::RenderWindow	mWindow;
	TextureHandler		mTexture;
	
	StateHandler		mStates;
};



#endif // !GAME_H

