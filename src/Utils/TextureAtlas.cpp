#include "TextureAtlas.h"

std::map<std::string, sf::Texture*> TextureAtlas::mTextures;
TextureAtlas* TextureAtlas::mInstance = nullptr;

TextureAtlas::TextureAtlas()
{

}

TextureAtlas* TextureAtlas::getInstance()
{
	if (mInstance)
		return mInstance;
	else
	{
		mInstance = new TextureAtlas();
		return mInstance;
	}
}

void TextureAtlas::loadTextureFromFile(const std::string& filename, const std::string& textureName)
{
	if (FILE* file = fopen(filename.c_str(), "r"))
		fclose(file);
	else
		throw std::runtime_error("Texture " + textureName + " - could not be found");

	sf::Texture* texturePtr = new sf::Texture();
	texturePtr->loadFromFile(filename);

	mTextures[textureName] = texturePtr;
}

sf::Texture* TextureAtlas::getTexture(const std::string& textureName)
{
	if (mTextures.find(textureName) == mTextures.end())
		throw std::runtime_error("Testure " + textureName + " - is not loaded");

	return mTextures[textureName];
}

void TextureAtlas::clear()
{
	for (auto it = mTextures.begin(); it != mTextures.end(); ++it)
		delete ((*it).second);
}
