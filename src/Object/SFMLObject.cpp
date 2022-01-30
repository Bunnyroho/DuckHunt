#include "SFMLObject.h"

SFMLObject::SFMLObject()
{
	mTexture = nullptr;
	
	mSize = sf::Vector2f();
	mPosition = sf::Vector2f();
}

SFMLObject::SFMLObject(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	create(texture, size, position);
}

void SFMLObject::create(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	mTexture = texture;

	mSprite.setTexture(*mTexture);
	mSprite.setOrigin(sf::Vector2f(mTexture->getSize().x / 2.0f, mTexture->getSize().y / 2.0f));
	mSprite.setScale(sf::Vector2f(size.x / (float)mTexture->getSize().x, size.y / (float)mTexture->getSize().y));
	mSprite.setPosition(position);

	mSize = size;
	mPosition = position;
}

void SFMLObject::draw(sf::RenderWindow& window)
{
	window.draw(mSprite);
}

void SFMLObject::setPosition(sf::Vector2f position)
{
	mSprite.setPosition(position);
	mPosition = position;
}

void SFMLObject::setSize(sf::Vector2f size)
{
	mSprite.setScale(sf::Vector2f(size.x / mSize.x, size.y / mSize.y));
	mSize = size;
}

void SFMLObject::setTexture(sf::Texture* texture)
{
	mSprite.setTexture(*texture);
}
