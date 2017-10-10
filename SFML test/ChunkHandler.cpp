#include "ChunkHandler.h"

ChunkHandler::ChunkHandler(unsigned chunkSize, ChunkProp & chunkProp, const SpriteProp & spriteProp)
{
	this->mSize = chunkSize*chunkSize;
	this->mChunks = new Chunk*[mSize];

	for (int i = 0; i < mSize; i++)
	{
		chunkProp.pos = this->calculatePosition(i, chunkSize) * (float)chunkProp.length * (float)spriteProp.spriteSize;
		this->mChunks[i] = new Chunk(chunkProp, spriteProp);
	}
}

ChunkHandler::~ChunkHandler()
{
	for (int i = 0; i < this->mSize; i++)
	{
		delete this->mChunks[i];
	}
	delete[] this->mChunks;
}

void ChunkHandler::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < this->mSize; i++)
	{
		if (this->mDrawingRect.contains(this->mChunks[i]->getPosition()))
		{
			this->mChunks[i]->draw(target, states);
		}
	}
}

void ChunkHandler::update(float dt)
{
}

void ChunkHandler::setDrawingRect(const sf::Vector2f & cameraCenter, const int  & offset)
{
	sf::FloatRect drawingRect;
	drawingRect.left = cameraCenter.x - offset;
	drawingRect.top = cameraCenter.y - offset;
	drawingRect.width = 2 * offset;
	drawingRect.height = 2 * offset;

	this->mDrawingRect = drawingRect;
}

sf::Vector2f ChunkHandler::calculatePosition(const unsigned & index, const unsigned & chunkSize) const
{
	unsigned x = (index % chunkSize);
	unsigned y = (index / chunkSize);

	return sf::Vector2f(x, y);
}

