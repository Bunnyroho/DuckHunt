#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

#include <Utils/EnumFishEndState.h>
#include <Utils/TextureAtlas.h>
#include <Utils/Config.h>
#include <Object/Animal.h>
#include <UI/Score.h>

class Fish : public Animal
{
private:
	float mSpeed;

	Animal* mPlayerPtr;
	Score* mScorePtr;

public:
	Fish(float speed, Animal* player, Score* scoreUIPtr, sf::Vector2f size, sf::Vector2f position = sf::Vector2f());

	virtual void update(float deltaTime);
};