#include "Game.h"



Game::Game()
	:	mWindow(sf::VideoMode(WINDOW_SIZE), "SFML works!"),
		mTexture("Resources/terrain.PNG")
{
	//testing to add game state
	mStates.emplace(new GameState(&mTexture));
	//initilizes gameState, which is on top of stack.
	mStates.top().init(&mWindow);


}


Game::~Game()
{
	
}

void Game::init()
{
	//Main loop of game
	while (mWindow.isOpen()) {

		sf::Event event;
		while (mWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				mWindow.close();
			}
			this->input(event);
		}
		
		
		//Update then draws the state that's in the top of StateHandler stack
		mStates.update(0);
		this->render(mWindow);
	}

}

void Game::render(sf::RenderWindow & window)
{
	mWindow.draw(mStates);
	mWindow.display();
	mWindow.clear();

}

void Game::input(const sf::Event & inputEvent)
{
	this->mStates.input(inputEvent);
}
