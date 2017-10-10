#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H

#include"SFML\Graphics.hpp"
#include<map>
#include"Entity.h"

enum TextureID {terrain};

class TextureHandler
{
public:
	TextureHandler(const std::string & fname);
	~TextureHandler();

	bool addTexture(const std::string & fname);

	sf::Texture * getTexture();

private:
	sf::Texture mTextures;
};

#endif
