#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>


class Entity : public sf::Drawable
{
public:
	Entity();
	~Entity();

	virtual void	draw(sf::RenderTarget & target, sf::RenderStates states) const = 0;
	virtual void	update(float dt) = 0;


	
};

#endif
