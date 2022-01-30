#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

#include <Utils/EnumFishEndState.h>
#include <Utils/TextureAtlas.h>
#include <Utils/Config.h>
#include <Object/SFMLObject.h>
#include <UI/Score.h>

class Fish : public SFMLObject
{
private:
	float mSpeed;

	SFMLObject* mPlayerPtr;
	Score* mScorePtr;

public:
	Fish(float speed, SFMLObject* player, Score* scoreUIPtr, sf::Vector2f size, sf::Vector2f position = sf::Vector2f());

	virtual void update(float deltaTime);
};