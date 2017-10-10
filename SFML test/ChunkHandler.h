#ifndef CHUNKHANDLER_H
#define CHUNKHANDLER_H

#include"Chunk.h"

class ChunkHandler : public Entity
{
public:
	ChunkHandler(unsigned chunkSize, ChunkProp & chunkProp, const SpriteProp & spriteProp);
	~ChunkHandler();

	void	draw(sf::RenderTarget & target, sf::RenderStates states) const;
	void	update(float dt);

	void setDrawingRect(const sf::Vector2f & cameraCenter, const int  & offset);

private:
	sf::Vector2f calculatePosition(const unsigned & index, const unsigned & chunkSize) const;
	//Every chunk that's inside the rectangle will be drawn
	sf::FloatRect mDrawingRect;
private:
	unsigned mSize;
	Chunk ** mChunks;

};

#endif