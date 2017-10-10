#ifndef STATE_H
#define STATE_H

#include "Entity.h"
#include"TextureHandler.h"


enum layers { background, midground, foreground };

typedef std::vector<std::vector<Entity*>> doubleVector;

class State : public sf::Drawable
{
public:
	State(TextureHandler * textures);
	~State();

	virtual void init(sf::RenderWindow * window) = 0;
	virtual void update(float dt) = 0;
	virtual void input(const sf::Event & inputEvent) = 0;
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

	//Choose between background, midground or foreground layer
	void addToLayer(layers layer, Entity * object);
protected:
	TextureHandler * mTextures;

private:
	unsigned int mlayerCount;
	doubleVector mLayers;
};


#endif
