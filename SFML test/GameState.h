#ifndef GAMESTATE_H
#define GAMESTATE_H

#include"State.h"
#include"Entity.h"
#include"ChunkHandler.h"

class GameState : public State
{
public:
	GameState(TextureHandler * textures);
	~GameState();

	void init(sf::RenderWindow * window);
	void update(float dt);
	void input(const sf::Event & inputEvent);

	//Camera
	void zoomView(float zoom, const float & delta);
	void dragCamera();

private:
	//Camera
	bool			mouseBtnDown;
	float		    mZoomAmount;
	unsigned		mDrawingDistance;
	sf::Vector2f	mOldPos;
	sf::View		mCamera;


	sf::RenderWindow * mRenderWindowAccess;

private:
	ChunkHandler * mChunks;
};

#endif
