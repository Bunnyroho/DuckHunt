#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <exception>

class TextureAtlas
{
private:
	TextureAtlas();

	static std::map<std::string, sf::Texture*> mTextures;
	static TextureAtlas* mInstance;

public:
	static TextureAtlas* getInstance();

	void loadTextureFromFile(const std::string& filename, const std::string& textureName);
	sf::Texture* getTexture(const std::string& textureName);

	void clear();
};