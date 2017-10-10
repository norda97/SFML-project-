#include "State.h"



State::State(TextureHandler * textures)
	: mLayers(3)
{
	mTextures = textures;
}


State::~State()
{
	for (int i = 0; i < mLayers.size(); i++)
	{
		for (int j = 0; j < mLayers[i].size(); j++)
		{
			delete mLayers[i][j];
		}
	}
}

void State::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < mLayers.size(); i++)
	{
		for (int j = 0; j < mLayers[i].size(); j++)
		{
			mLayers[i][j]->draw(target, states);
		}
	}
	
}

//Choose between background, midground or foreground layer
void State::addToLayer(layers layer, Entity * object)
{
	switch (layer) {
	case layers::background:
		mLayers[0].push_back(object);
		break;
	case layers::midground:
		mLayers[1].push_back(object);
		break;
	case layers::foreground:
		mLayers[2].push_back(object);
		break;
	}
}
