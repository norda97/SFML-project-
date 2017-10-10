#include "Chunk.h"

Chunk::Chunk(const ChunkProp & chunkProp, const SpriteProp & spriteProp)
{
	this->mTileSize = spriteProp.spriteSize;
	this->mChunkSize = chunkProp.length*chunkProp.length;
	//Creates all activeobjects in the chunk
	mChunk = new ActiveObject[this->mChunkSize];

	
	this->setTexture(spriteProp);
	this->setSize(spriteProp.spriteSize);
	this->setPosition(chunkProp);

}

Chunk::~Chunk()
{
	delete[] mChunk;
}

//Gives access to chunkObject at x,y of pos
ActiveObject & Chunk::operator[](const sf::Vector2u &  pos)
{
	int position = pos.x + pos.y * sqrt(this->mChunkSize);
	return mChunk[position];
}

void Chunk::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (unsigned i = 0; i < this->mChunkSize; i++)
	{
		mChunk[i].draw(target, states);
	}
}

void Chunk::update(float dt)
{
}

void Chunk::setSize(const unsigned & spriteSize)
{
	for (unsigned i = 0; i < this->mChunkSize; i++)
	{
		mChunk[i].setSize(spriteSize);
	}
}

void Chunk::setTexture(const SpriteProp & spriteProp)
{
	for (unsigned i = 0; i < this->mChunkSize; i++)
	{
		mChunk[i].setTexture(spriteProp);
	}
}

void Chunk::setPosition(const ChunkProp & chunkProp)
{
	this->mPos = chunkProp.pos;
	unsigned length = sqrt(this->mChunkSize);
	sf::Vector2f currPos;
	//positions all activeobjects to chunkPos
	for (unsigned i = 0; i < length; i++)
	{
		for (unsigned j = 0; j < length; j++) {
			currPos = this->mPos;
			currPos.x += j * this->mTileSize;
			currPos.y += i * this->mTileSize;
			
			mChunk[i*length + j].setPosition(currPos);
		}
	}
	const sf::Vector2f middle(chunkProp.pos.x + (chunkProp.length / 2) * this->mTileSize, chunkProp.pos.y + (chunkProp.length / 2) * this->mTileSize);
	this->mPos = middle;
}
