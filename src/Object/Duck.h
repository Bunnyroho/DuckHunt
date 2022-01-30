#pragma once

#include <SFML/Graphics.hpp>

#include <Utils/TextureAtlas.h>
#include <Utils/Config.h>
#include <Object/SFMLObject.h>

class Duck : public SFMLObject
{
private:
	float mSpeed = 500.0f;

public:
	Duck(float speed, sf::Vector2f size, sf::Vector2f position = sf::Vector2f());

	virtual void update(float deltaTime);
};