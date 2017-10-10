#include "ActiveObject.h"



ActiveObject::ActiveObject()
{
}

ActiveObject::ActiveObject(const ActiveObject & other)
{
	this->setTexture(other.mProps);
	this->setPosition(other.getPosition());
	
}

ActiveObject::ActiveObject(const SpriteProp & spriteProp)
{
	setTexture(spriteProp);
}


ActiveObject::~ActiveObject()
{
}

void ActiveObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(mSprite);
}

void ActiveObject::update(float dt)
{
}

void ActiveObject::setSize(const unsigned & spriteSize)
{
	mProps.spriteSize = spriteSize;
	this->mSprite.setScale((float)spriteSize / this->mProps.textureSize, (float)spriteSize / this->mProps.textureSize);
}

void ActiveObject::setTexture(const SpriteProp & spriteProp)
{
	mProps = spriteProp;

	sf::IntRect crop(mProps.pos * (int)mProps.textureSize, sf::Vector2i(mProps.textureSize, mProps.textureSize));

	mSprite.setTexture(*mProps.texture);

	mSprite.setTextureRect(crop);
}

void ActiveObject::setPosition(const sf::Vector2f & pos)
{
	mSprite.setPosition(pos);
}

const SpriteProp & ActiveObject::getProperties() const
{
	return mProps;
}
