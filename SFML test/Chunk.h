#ifndef CHUNK_H
#define CHUNK_H

#include"ActiveObject.h"

struct ChunkProp {
	sf::Vector2f pos;
	uint8_t length;

	ChunkProp(sf::Vector2f pos, uint8_t length) { this->length = length; this->pos = pos; };
};

class Chunk : public Entity
{
public:
	Chunk(const ChunkProp & chunkProp, const SpriteProp & spriteProp);
	~Chunk();

	ActiveObject & operator[](const sf::Vector2u & pos);

	void	draw(sf::RenderTarget & target, sf::RenderStates states) const;
	void	update(float dt);

	void	setSize(const unsigned & spriteSize);
	void	setTexture(const SpriteProp & spriteProp);
	void	setPosition(const ChunkProp & chunkProp);

	const sf::Vector2f & getPosition() { return this->mPos; };
private:
	sf::Vector2f	mPos;
	unsigned		mChunkSize;
	unsigned		mTileSize;
	ActiveObject*	mChunk;

};

#endif
