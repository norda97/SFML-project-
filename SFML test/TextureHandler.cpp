#include "TextureHandler.h"

TextureHandler::TextureHandler(const std::string & fname)
{
	addTexture(fname);
}

TextureHandler::~TextureHandler()
{
}

bool TextureHandler::addTexture(const std::string & fname)
{
	return mTextures.loadFromFile(fname);
}

sf::Texture * TextureHandler::getTexture()
{
	return &mTextures;
}
