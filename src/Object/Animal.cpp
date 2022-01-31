#include "Animal.h"

Animal::Animal()
{
	mTexture = nullptr;
	
	mSize = sf::Vector2f();
	mPosition = sf::Vector2f();
}

Animal::Animal(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	create(texture, size, position);
}

void Animal::create(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	mTexture = texture;

	mSprite.setTexture(*mTexture);
	mSprite.setOrigin(sf::Vector2f(mTexture->getSize().x / 2.0f, mTexture->getSize().y / 2.0f));
	mSprite.setScale(sf::Vector2f(size.x / (float)mTexture->getSize().x, size.y / (float)mTexture->getSize().y));
	mSprite.setPosition(position);

	mSize = size;
	mPosition = position;
}

void Animal::draw(sf::RenderWindow& window)
{
	window.draw(mSprite);
}

void Animal::setPosition(sf::Vector2f position)
{
	mSprite.setPosition(position);
	mPosition = position;
}

void Animal::setSize(sf::Vector2f size)
{
	mSprite.setScale(sf::Vector2f(size.x / mSize.x, size.y / mSize.y));
	mSize = size;
}

void Animal::setTexture(sf::Texture* texture)
{
	mSprite.setTexture(*texture);
}
