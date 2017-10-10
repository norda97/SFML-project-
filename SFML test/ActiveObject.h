#ifndef ACTIVEOBJECT_H
#define ACTIVEOBJECT_H

#include"Entity.h"


struct SpriteProp {
	sf::Texture * texture;
	unsigned textureSize;
	int spriteSize;
	sf::Vector2i pos;

	SpriteProp(int spriteSize = 32, sf::Vector2i texturePos = sf::Vector2i(0, 0), sf::Texture * texture = nullptr, unsigned textureSize = 64)
	{
		this->texture = texture;
		this->pos = texturePos;
		this->textureSize = textureSize;
		this->spriteSize = spriteSize;
	};
};

class ActiveObject : public Entity
{
public:
	ActiveObject();
	ActiveObject(const ActiveObject & other);
	ActiveObject(const SpriteProp & spriteProp);
	~ActiveObject();

	void	draw(sf::RenderTarget & target, sf::RenderStates states) const;
	void	update(float dt);

	void	setSize(const unsigned & spriteSize);
	void	setTexture(const SpriteProp & spriteProp);
	void	setPosition(const sf::Vector2f & pos);

	const sf::Vector2f & getPosition() const { return mSprite.getPosition(); };
	const sf::Texture *	 getTexture() const { return mSprite.getTexture(); };
	const SpriteProp &	 getProperties() const;

private:
	SpriteProp		mProps;
	sf::Sprite		mSprite;
};

#endif
