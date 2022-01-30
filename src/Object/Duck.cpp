#include "Duck.h"

Duck::Duck(float speed, sf::Vector2f size, sf::Vector2f position)
{
	create(TextureAtlas::getInstance()->getTexture("duckRTexture"), size, position);

	mSpeed = speed;
}

void Duck::update(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		mPosition += sf::Vector2f(-mSpeed * deltaTime, 0.0f);
		setTexture(TextureAtlas::getInstance()->getTexture("duckLTexture"));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		mPosition += sf::Vector2f(mSpeed * deltaTime, 0.0f);
		setTexture(TextureAtlas::getInstance()->getTexture("duckRTexture"));
	}

	if (mPosition.x < mSize.x / 2.0f)
		mPosition = sf::Vector2f(mSize.x / 2.0f, mSprite.getPosition().y);
	if (mPosition.x > WINDOW_WIDTH - mSize.x / 2.0f)
		mPosition = sf::Vector2f(800.0f - mSize.x / 2.0f, mSprite.getPosition().y);

	mSprite.setPosition(mPosition);
}
