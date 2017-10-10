#include "GameState.h"

#include<iostream>

GameState::GameState(TextureHandler * textures)
	: State(textures),
	mZoomAmount(1.1),
	mCamera(sf::FloatRect(0, 0, 640, 480)),
	mDrawingDistance(640),
	mChunks(new ChunkHandler(25, ChunkProp(sf::Vector2f(0, 0), 4), SpriteProp(32, sf::Vector2i(0, 0), this->mTextures->getTexture())))

	
{
	
}

GameState::~GameState()
{
}

void GameState::init(sf::RenderWindow * window)
{
	this->mRenderWindowAccess = window;
	this->addToLayer(layers::midground, this->mChunks);
	
}

void GameState::update(float dt)
{
	this->mChunks->setDrawingRect(this->mCamera.getCenter(), this->mDrawingDistance);
	
}

void GameState::input(const sf::Event & inputEvent)
{

	if (inputEvent.type == sf::Event::MouseButtonPressed)
	{
		if (inputEvent.mouseButton.button == sf::Mouse::Left && !this->mouseBtnDown)
		{
			this->mOldPos = this->mRenderWindowAccess->mapPixelToCoords(sf::Mouse::getPosition(*this->mRenderWindowAccess));
			this->mouseBtnDown = true;
			std::cout << "mousePos: " << mOldPos.x << "	" << mOldPos.y << std::endl;
		}
	}

	//Released button
	if (inputEvent.type == sf::Event::MouseButtonReleased)
		this->mouseBtnDown = false;
	
	//Camera movement
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		this->dragCamera();

	//Camera zoom
	if (inputEvent.type == sf::Event::MouseWheelScrolled) 
		this->zoomView(this->mZoomAmount, inputEvent.mouseWheelScroll.delta);

}

void GameState::zoomView(float zoom, const float & delta)
{
	if (delta > 0)
		this->mCamera.zoom(1.f / zoom);
	else if (delta < 0)
		this->mCamera.zoom(zoom);

	this->mRenderWindowAccess->setView(this->mCamera);
}

void GameState::dragCamera()
{
	const sf::Vector2f newPos(this->mRenderWindowAccess->mapPixelToCoords(sf::Mouse::getPosition(*this->mRenderWindowAccess)));
	const sf::Vector2f deltaPos = this->mOldPos - newPos;

	this->mCamera.move(deltaPos);
	this->mRenderWindowAccess->setView(this->mCamera);
}


