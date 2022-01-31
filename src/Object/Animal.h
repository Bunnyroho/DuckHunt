#pragma once

#include <SFML/Graphics.hpp>

#include <Interface/IDrawable.h>
#include <Interface/IUpdatable.h>

class Animal : public IDrawable, public IUpdatable
{
protected:
	sf::Texture* mTexture;
	sf::Sprite mSprite;

	sf::Vector2f mSize;
	sf::Vector2f mPosition;

	bool isDesignatedForTermination = false;

public:
	Animal();
	Animal(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position = sf::Vector2f());

	void create(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position = sf::Vector2f());

	virtual void draw(sf::RenderWindow& window);
	virtual void update(float deltaTime) {};

	sf::Vector2f getPosition() { return mPosition; }
	sf::Vector2f getSize() { return mSize; }
	bool getIsDesignatedForTermination() { return isDesignatedForTermination; }

	void setPosition(sf::Vector2f position);
	void setSize(sf::Vector2f size);
	void setTexture(sf::Texture* texture);
};